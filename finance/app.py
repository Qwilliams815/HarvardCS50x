import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Create portfolio table in db if one doesnt exist

    # db.execute("DROP TABLE portfolio")
    # db.execute("UPDATE users SET cash = ? WHERE id = ?", 10000.00, session["user_id"])


    try:
        db.execute("SELECT * FROM portfolio")
    except:
        db.execute("CREATE TABLE portfolio (user_portfolio_id INTEGER, symbol TEXT NOT NULL, name TEXT NOT NULL, shares INTEGER, price FLOAT, total FLOAT)")

    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    print(cash)

    return render_template("index.html", portfolio=db.execute("SELECT * FROM portfolio WHERE user_portfolio_id = ?", session["user_id"]), cash=db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"]))
    # cash from users, everything else from portfolio.

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":


        # Grab symbol and shares from form
        symbol = lookup(request.form.get("symbol"))
        shares = int(request.form.get("shares"))
        print("TESTESTESTESTEST")
        print(db.execute("SELECT symbol FROM portfolio WHERE user_portfolio_id = ?", session["user_id"]))

        # Ensure valid symbol was submitted
        if not symbol or symbol == None:
            return apology("Invalid Symbol", 403)

        # Ensure valid # of shares
        elif not shares or shares < 1:
            return apology("Invalid Shares Amount", 403)

        else:

            total_cost = symbol['price'] * shares
            cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]['cash']

            # if portfolio_cash == []:
            #     db.execute("INSERT INTO portfolio (cash) VALUE (?)", default)

            if cash - total_cost < 0:
                return apology("Insufficient Funds")

            else:
                symbols = [sym['symbol'] for sym in db.execute("SELECT symbol FROM portfolio WHERE user_portfolio_id = ?", session["user_id"])]
                print("SYMBOLS: ", symbols)

                if symbol['symbol'] in symbols:
                    current_shares = db.execute("SELECT shares FROM portfolio WHERE symbol = ? AND user_portfolio_id = ?", symbol['symbol'], session["user_id"])[0]['shares']
                    current_total = db.execute("SELECT total FROM portfolio WHERE symbol = ? AND user_portfolio_id = ?", symbol['symbol'], session["user_id"])[0]['total']
                    # print("TYPES: ", type(current_shares), type(shares), type(current_total), type(total_cost))

                    db.execute("UPDATE portfolio (shares, total) VALUES (?, ?) WHERE symbol = ? AND user_portfolio_id = ?", current_shares+shares, current_total+total_cost, symbol['symbol'], session["user_id"])
                    db.execute("UPDATE users SET (cash) = ? WHERE id = ?", cash-total_cost, session["user_id"])
                    #already symbol already in portfolio, just add the shares and total
                else:
                    db.execute("INSERT INTO portfolio (user_portfolio_id, symbol, name, shares, price, total) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], symbol['symbol'], symbol['name'], shares, symbol['price'], total_cost)
                    db.execute("UPDATE users SET (cash) = ? WHERE id = ?", cash-total_cost, session["user_id"])

                return redirect("/")
            # else, subtract purchased amount from cash amount and update users table


    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    #test yet another test, wouldnt you believe it; another test

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        quote = lookup(request.form.get("quote"))
        if quote != None:
            return render_template("quoted.html", quote=quote)
        else:
            return apology("invalid stock symbol", 403)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password confirmation was submitted and a match
        elif not request.form.get("confirm-password") or request.form.get("confirm-password") != request.form.get("password"):
            return apology("Password confirmation must match Password", 403)


        else:

            # Add user to user database
            try:
                db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), generate_password_hash(request.form.get("password")))
            except:
                return apology("Username already in use", 500)

            # Query database for username
            rows = db.execute("SELECT * FROM users WHERE username = ?",
                          request.form.get("username"))

            # Remember which user has logged in
            session["user_id"] = rows[0]["id"]

            # Redirect user to home page
            return redirect("/")

    else:
        # Show register page
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
    #Thank you for not timing out

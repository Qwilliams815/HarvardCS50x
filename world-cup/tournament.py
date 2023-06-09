# Simulate a sports tournament

import csv
import sys
import random


# Number of simluations to run
N = 1000


def main():
    sims = N

   # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Reads teams into memory from file as and array of dictionaries
    teams = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)

        # Change each rating value from string to int
        for row in reader:
            row["rating"] = int(row["rating"])
            teams.append(row)
            # print(row)

    counts = {}

    # TODO: Simulate N tournaments and keep track of win counts

    # Initialize all teams count to 0
    for team in teams:
        counts[teams[teams.index(team)]["team"]] = 0

    # Tally team wins per each tournament simulation
    while sims != 0:
        counts[simulate_tournament(teams)] += 1
        sims -= 1

    print(counts)

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""

    # Until there is only 1 winning team remaining, run simulate_round(teams)
    while len(teams) != 1:
        teams = simulate_round(teams)

    # Return name of winning team
    return teams[0]["team"]


if __name__ == "__main__":
    main()

number = "378282246310005"
amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]

for num in amex:
    if number.startswith(num) and len(number) == 15:
        print("AMEX")
        quit()

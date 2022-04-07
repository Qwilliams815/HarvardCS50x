import re


number = "5555555555554444"
number_pattern = "[0-9]"

amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]


for num in master_card:
    print(num)
    if number.startswith(num) and len(number) == 16:
        print("MASTERCARD")
        quit()

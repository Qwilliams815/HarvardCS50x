from cs50 import get_int

number = input("Number: ")

num_sum_1 = 0
for num in number[-2::-2]:
    num_sum_1 += int(num) * 2

num_sum_2 = 0
for num in number[-1::-2]:
    num_sum_2 += int(num)

if (num_sum_1 + num_sum_2) % 10 != 0:
    print("INVALID")
    quit()

amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]

for num in amex:
    if number.startswith(num):
        print("AMEX")
for num in master_card:
    if number.startswith(num):
        print("MASTERCARD")
if number[0] == "4":
    print("VISA")



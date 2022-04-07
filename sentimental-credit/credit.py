from cs50 import get_int

number = input("Number: ")

# Number cannot be negative, contain alpha characters, too short, too long
# while number.isdigit() == False:
#     print("INVALID")
#     number = input("Number: ")

if len(number) < 13 or len(number) > 16:
    print("INVALID")
    # number = input("Number: ")


# Luhn's Algorithm

# 371449635398431 AMEX
num_list_1 = ""
for num in number[-2::-2]:
    num_list_1 += str(int(num) * 2)
# print(num_list_1)

num_sum_1 = 0
for num in num_list_1:
    num_sum_1 += int(num)
# print(num_sum_1)

num_sum_2 = 0
for num in number[-1::-2]:
    num_sum_2 += int(num)
    # print(num)
#print("num sum 2:", num_sum_2)

while (num_sum_1 + num_sum_2) % 10 != 0:
    print("INVALID")
    number = input("Number: ")

# Verify card company base on starting digits
amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]

for num in amex:
    if number.startswith(num) and len(number) == 15:
        print("AMEX")
        quit()

for num in master_card:
    if number.startswith(num) and len(number) == 16:
        print("MASTERCARD")
        quit()

if len(number) == 13 or len(number) == 16:
    if number[0] == "4":
        print("VISA")
        quit()

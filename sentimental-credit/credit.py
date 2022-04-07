# Used built-in input() to keep card number input as string format
number = input("Number: ")

# Card number length check
if len(number) < 13 or len(number) > 16:
    print("INVALID")
    quit()

# Luhn's Algorithm
# Starting from the end, take every other number, multiply by 2, add all digits to string
num_list_1 = ""
for num in number[-2::-2]:
    num_list_1 += str(int(num) * 2)

# Iterate over num_list string, adding each int(digit) to num_sum_1
num_sum_1 = 0
for num in num_list_1:
    num_sum_1 += int(num)

# Add up the rest of the CC numbers
num_sum_2 = 0
for num in number[-1::-2]:
    num_sum_2 += int(num)

# Sum and check modulo
if (num_sum_1 + num_sum_2) % 10 != 0:
    print("INVALID")
    quit()

# Verify card company based on card starting digits
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

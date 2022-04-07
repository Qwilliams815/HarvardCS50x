from cs50 import get_int

number = get_int("Number: ")

# AMEX start with 34, 37
# Mastercard start with 51, 52, 53, 54, or 55
# VISA start with 4

num_sum = 0
for num in number[-1::-1]:
    num_sum += num * 2
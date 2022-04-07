from cs50 import get_int

number = get_int("Number: ")

# AMEX start with 34, 37
# Mastercard start with 51, 52, 53, 54, or 55
# VISA start with 4

num_sum_1 = 0
for num in number[-2::-2]:
    num_sum_1 += num * 2

num_sum_2 = 0
for num in number[-1::-2]:
    num_sum_2 += num

if (num_sum_1 + num_sum_2) % 10 == 0;
    return True



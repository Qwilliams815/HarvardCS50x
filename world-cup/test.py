number = "371449635398431"
amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]

# 371449635398431 AMEX

num_sum_1 = 0
for num in number[-2::-2]:
    num_sum_1 += int(num) * 2
    print(num)
print("sum1:", num_sum_1)

num_sum_2 = 0
for num in number[-1::-2]:
    num_sum_2 += int(num)
    print(num)
print("sum1:", num_sum_1)

if (num_sum_1 + num_sum_2) % 10 != 0:
    print("INVALID3")
    quit()

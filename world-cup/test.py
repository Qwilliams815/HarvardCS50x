# import re

# def useRegex(input):
#     pattern = re.compile(r"^[a-zA-Z]{3,7}$", re.IGNORECASE)
#     # return pattern.match(input)
#     print(pattern.match(input))

# word = "as2gdf"
# useRegex(word)
# if not useRegex(word):
#     print("Failed")
# else:
#     print("passed")

# number = "5555555555554444"
# number_pattern = "[0-9]"

# amex = ["34", "37"]
# master_card = ["51", "52", "53", "54", "55"]


# for num in master_card:
#     print(num)
#     if number.startswith(num) and len(number) == 16:
#         print("MASTERCARD")
#         quit()

# def is_one(number):
#     if number == 1:
#         print("yes its one")


# def is_two(number):
#     if number == 2:
#         print("yes its two")

# num = 3
# if not is_one(num) and not is_two(num):
#     print("num is neither")

dicts = [{'username': 'bri'}, {'username': 'brian'}]
name = 'brian'
if {'username': name} in dicts:
    print("found")

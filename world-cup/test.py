number = "378282246310005"
amex = ["34", "37"]
master_card = ["51", "52", "53", "54", "55"]

if len(number) < 13 or len(number) > 16:
    print("INVALID")
    number = input("Number: ")

for i in number:
    if i.isalpha() == True or i == '-':
        print("INVALID")
        number = input("Number: ")

for num in amex:
    if number.startswith(num) and len(number) == 15:
        print("AMEX")
        quit()

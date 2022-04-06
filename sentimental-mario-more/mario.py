# TODO
height = int(input("Height: "))

level = 1

for level in range(height):
    print(('#' * level) + ' ' * (height-1))
    level += 1

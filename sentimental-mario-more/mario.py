# TODO
height = int(input("Height: "))

hashes = 0
spaces = height-1

for level in range(height):
    print(('#' * level) + ' ' * (height-1))
    level += 1

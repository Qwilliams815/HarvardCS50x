
# Gather pyramid height from user input
height = int(input("Height: "))

# Establish initial hash/space amounts
hashes = 1
spaces = height-1

i = 0
while i < height:
    print((' ' * spaces) + ('#' * hashes) + "  " + ('#' * hashes) + (' ' * spaces))
    spaces -= 1
    hashes += 1
    i += 1

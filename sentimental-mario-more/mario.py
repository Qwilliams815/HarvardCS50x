from cs50 import get_int


# Gather pyramid height from user input
height = get_int("Height: ")

# Incorrect input handling
while height not in range(1, 9):
    height = get_int("Height: ")

# Establish initial hash/space counts
hashes = 1
spaces = height-1

# Generate each line, inc/decrementing hash and space counts
while hashes != height+1:
    print((' ' * spaces) + ('#' * hashes) +
          "  " + ('#' * hashes))
    spaces -= 1
    hashes += 1

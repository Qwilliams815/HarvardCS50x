
# Gather pyramid height from user input
height = int(input("Height: "))

while height 


# Establish initial hash/space counts
hashes = 1
spaces = height-1

# Generate each line, inc/decrementing hash and space counts
while hashes != height+1:
    print((' ' * spaces) + ('#' * hashes) +
          "  " + ('#' * hashes) + (' ' * spaces))
    spaces -= 1
    hashes += 1

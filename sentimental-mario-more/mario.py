
# Gather pyramid height from user input
try:
    height = int(input("Height: "))
except:
    print("Height must be numeric")
    quit()


# Establish initial hash/space counts
hashes = 1
spaces = height-1

# Generate each line, inc/decrementing hash and space counts
while hashes != height+1:
    print((' ' * spaces) + ('#' * hashes) +
          "  " + ('#' * hashes) + (' ' * spaces))
    spaces -= 1
    hashes += 1

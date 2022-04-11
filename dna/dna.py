import csv
import sys

args = sys.argv


def main():

    # TODO: Check for command-line usage
    # $ python dna.py databases/large.csv sequences/5.txt
    if len(args) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        quit()

    # TODO: Read database file and subsequences into variables
    sub_sequences = []
    people = []
    with open(args[1]) as db:
        reader = csv.reader(db)
        for row in reader:
            if row[0] == "name":
                for item in row[1:]:
                    sub_sequences.append(item)
            else:
                people.append(row)
    print(people)

    # TODO: Read DNA sequence file into a variable
    with open(args[2], 'r') as dna:
        sequence = dna.read()
        # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence
    found_strs = []
    for seq in sub_sequences:
        found_strs.append(longest_match(sequence, seq))

    # TODO: Check database for matching profiles
    for str_ in found_strs:
        for person in persons:

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

from cs50 import get_string

# TODO input some text, output the grade level for the text
text = get_string("Text: ")

# TODO Coleman-Liau formula 0.0588 * L - 0.296 * S - 15.8 = grade
# L is avg letters per 100 words
# S is avg sentances per 100 words
# X is the grade level

letter_count = 0
word_count = 0
sentance_count = 0

# Unicode values for period, question mark, and exclamation point
punctuation = [46, 63, 33]

for letter in text:
    if character.isalpha() == True:
        letter_count += 1
    if ord(letter) is space:
        word_count += 1
    elif ord(letter) is period or question mark or exclamation point
        sentance_count += 1

grade = round(grade)
if grade > 16:
    print("Grade: 16+")
elif grade < 1:
    print("Before Grade 1)
else:
    print(f"Grade: {grade}")
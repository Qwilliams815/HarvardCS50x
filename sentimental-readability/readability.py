from cs50 import get_string

# TODO input some text, output the grade level for the text
text = get_string("Text: ")

# TODO Coleman-Liau formula 0.0588 * L - 0.296 * S - 15.8 = grade
# L is avg letters per 100 words
# S is avg sentances per 100 words
# X is the grade level

grade = 0

letter_count = 0
if text[0] != ''
word_count = 1
sentence_count = 0

# Unicode values for period, question mark, and exclamation point
punctuation = ['.', '?', '!']

for letter in text:
    if letter.isalpha() == True:
        letter_count += 1
    if letter == ' ':
        word_count += 1
    elif letter in punctuation:
        sentence_count += 1

print(letter_count)
print(word_count)
print(sentence_count)
print(len(text))

grade = round(grade)
if grade > 16:
    print("Grade: 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {grade}")

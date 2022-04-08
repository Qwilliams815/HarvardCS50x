from cs50 import get_string

# Gather text input form user and establish starting letter/word/sentence counts
text = get_string("Text: ")

letter_count = 0
word_count = 1
sentence_count = 0
punctuation = ['.', '?', '!']

# Iterate over text, increment appropriate letter/word/sentence counts
for letter in text:
    if letter.isalpha() == True:
        letter_count += 1
    if letter == ' ':
        word_count += 1
    elif letter in punctuation:
        sentence_count += 1

# Coleman-Liau formula 0.0588 * L - 0.296 * S - 15.8 = grade
grade = round(0.0588 * letter_count / word_count * 100 -
              0.296 * sentence_count / word_count * 100 - 15.8)

if grade >= 16:
    print("Grade: 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade: {grade}")

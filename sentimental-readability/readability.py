from cs50 import get_string

# TODO input some text, output the grade level for the text
text = get_string("Text: ")

# TODO Coleman-Liau formula 0.0588 * L - 0.296 * S - 15.8
# L is avg letters per 100 words
# S is avg sentances per 100 words

for letter in text:
    if ord(letter) is space:
        word_count += 1
    elif ord(letter) is period or question mark or exclamation point
        sentance_count += 1

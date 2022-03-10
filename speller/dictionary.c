// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2500;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i]->word == word)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    int ascii = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        ascii += word[i];
    }

    ascii *= strlen(word);
    ascii *= word[0];
    // double new = pow(ascii, strlen(word));
    // return printf("%s -- %i\n\n", word, ascii % 2500);
    return ascii % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO: Take dictionary, load it into a hash table
    // If load succesful, return True, else return false
    bool loaded = true;
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        printf("Could not open Dictionary.\n");
        loaded = false;
    }

    // Scan words from dictionary file
    char word[45];
    int i = 0;
    while (fgets(word, 45, dict))
    {
        // Allocate Memory for node
        node *n = malloc(sizeof(node));

        // Fill node with word and next address
        strcpy(n->word, word);
        n->next = NULL;

        // Assign node to linked hashmap spot based on hash function
        // Get hash index of word
        int word_index = hash(word);
        printf("%i -- %s\n", word_index, word);
        if (i > 15) {
            continue;
        }
        i++;

        // Populate new node properties
        table[word_index] = n;
    }
    fclose(dict);
    return loaded;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //loop through hash table
    //if next pointer is null, count++
    //else, for each word in linked list, count++
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    // TODO
    return false;
}

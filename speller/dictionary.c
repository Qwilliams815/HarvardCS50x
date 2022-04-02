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

// Establish size counter for counting words in dictionary
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Create lowercase version of word
    // char *lower_word = malloc(strlen(word) + 1);
    // strcpy(lower_word, word);

    // for (int i = 0; i < strlen(word); i++)
    // {
    //     lower_word[i] = tolower(lower_word[i]);
    // }

    // Check table index of hash(lower_word)
    //node *curr = table[hash(lower_word)];
    node *curr = table[hash(word)];
    // As long as the current node isnt NUll, traverse linked list
    while (curr != NULL)
    {
        //if (strcmp(curr->word, lower_word) == 0)
        if (strcmp(curr->word, word) == 0)
        {
            //free(lower_word);
            return true;
        }
        curr = curr->next;
    }
    //free(lower_word);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // Turn word Lowercase
    // char lower_word[LENGTH];
    // for (int i = 0; i < strlen(word); i++)
    // {
    //     lower_word[i] = tolower(word[i]);
    // }

    char *lower_word = malloc(strlen(word) + 1);
    strcpy(lower_word, word);

    for (int i = 0; i < strlen(word); i++)
    {
        lower_word[i] = tolower(lower_word[i]);
    }

    int ascii = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        ascii += word[i];
    }

    ascii *= strlen(word);
    ascii *= word[0];
    free(lower_word);
    return ascii % (N - 1);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    // Open dictionary
    FILE *dict = fopen(dictionary, "r");

    // If dictionary doesnt load properly, return false.
    if (dict == NULL)
    {
        printf("Could not open Dictionary.\n");
        return false;
    }

    // Set all initial table buckets to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Scan each word from dictionary file
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Increment size counter
        word_count++;

        // Allocate Memory for node, copy current word to node->word property.
        node *current = malloc(sizeof(node));

        // Check if malloc returned NULL
        if (current == NULL)
        {
            return false;
        }

        // Update current node word value
        strcpy(current->word, word);
        int index = hash(word);

        // Insert node into Hash table at table[hash(word)],
        // Set next pointer to whatever node already lives at index
        current->next = table[index];
        // Set current as new head of linked list at index
        table[index] = current;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *curr = table[i];
            while (curr != NULL)
            {
                node* tmp = curr;
                curr = curr->next;
                //TODO: Double free aborts code
                free(tmp);
            }
        }
    }

    return true;
}

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

    // Turn word lowercase
    // char *lower_word[45];
    // for (int i = 0; i < strlen(word); i++)
    // {
    //     *lower_word[i] = tolower(word[i]);
    // }

    // int word_index = hash(lower_word);

    // // word index == table[word_index]->word

    // if table
    //     [hash(lower_word)]

    //         for (int i = 0; i < N; i++)
    //     {
    //         if (table[i]->word == word)
    //         {
    //             return true;
    //         }
    //     }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // Turn word Lowercase
    char lower_word[45];
    for (int i = 0; i < strlen(word); i++)
    {
        lower_word[i] = tolower(word[i]);
    }

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

    // Set all table buckets to null
    for (int j = 0; j < N; j++)
    {
        table[j] = NULL;
        // table[j] = n;
    }

    // Scan words from dictionary file
    char word[45];
    while (fgets(word, 45, dict))
    {
        // Allocate Memory for node
        node *n = malloc(sizeof(node));
        int index = hash(word);

        // If hash(word) isnt empty, traverse the linked list until you find the last node
        node *current = table[index];
        while (table[index] != NULL)
        {
            current = current->next;
        }

        current = n;
        strcpy(current->word, word);
        current->next = NULL;

        // Fill node with word and next address

        // Assign node to linked hashmap spot based on hash function
        // Get hash index of word
        int word_index = hash(word);
        // printf("%i -- %s\n", word_index, word);


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
    // loop through hash table
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        // If index is start of linked list, for each word in linked list, count++
        if (table[i]->next != NULL)
        {
            node *head = table[i]->next;
            node *temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        // Else, if next pointer is null, count++
        else
        {
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // traverse table, free each node if node->next == NULL, if linked list, free from end to start.

    // TODO
    return false;
}

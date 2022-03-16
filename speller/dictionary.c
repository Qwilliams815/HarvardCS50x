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

    // Open dictionary
    FILE *dict = fopen(dictionary, "r");

    // If dictionary doesnt load properly, return false.
    if (dict == NULL)
    {
        printf("Could not open Dictionary.\n");
        return false;
    }

    // Set all initial table buckets to NULL
    for (int j = 0; j < N; j++)
    {
        table[j] = NULL;
    }

    // Scan each word from dictionary file
    char word[45];
    // while (fgets(word, 45, dict))
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Allocate Memory for node, copy current word to node->word property.
        node *current = malloc(sizeof(node));

        // Check if malloc returned NULL
        if (current == NULL)
        {
            return false;
        }

        strcpy(current->word, word);
        current->next = NULL;
        int index = hash(word);

        // Insert node into Hash table at table[hash(word)],
        if (table[index] == NULL)
        {
            // Set next pointer to whatever node already in at index
            current->next = table[index];
            // Set current as new head of linked list at index
            table[index] = current;
        }
        else
        {

            current->next = table[index];
            table[index] = current;

            // while (table[index] != NULL)
            // {
            //     table[index] = table[index]->next;
            // }
            // table[index] = current;

            // // If index is taken, create/ traverse a linked list, append current to the end.
            // if (table[index] != NULL)
            // {
            //     while (current->next != NULL) {
            //         current = current->next;
            //     }
            // }
        }
    }
    fclose(dict);
    return true;
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

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
const unsigned int N = 5;

// Establish size counter for counting words in dictionary
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // Create lowercase version of word
    char lower_word[LENGTH];
    for (int i = 0; i < strlen(word); i++)
    {
        lower_word[i] = tolower(word[i]);
    }

    // Check table index of hash(lower_word)
    node *curr = table[hash(lower_word)];
    // As long as the current node isnt NUll, traverse linked list
    while (curr != NULL)
    {
        if (strcmp(curr->word, lower_word) == 0)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';

    // Turn word Lowercase
    char lower_word[LENGTH];
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
    return ascii % (N - 1);
    // N - 1??
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
    // while (fgets(word, 45, dict))
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Increment size counter
        //printf("%s\n", word);
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

    for (int i = 0; i<N; i++) {
        printf("%s\n", table[i]->word);
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // // TODO
    // // loop through hash table
    // int count = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     // If index is start of linked list, for each word in linked list, count++
    //     if (table[i]->next != NULL)
    //     {
    //         node *head = table[i]->next;
    //         node *temp = head;
    //         while (temp != NULL)
    //         {
    //             count++;
    //             temp = temp->next;
    //         }
    //     }
    //     // Else, if next pointer is null, count++
    //     else
    //     {
    //         count++;
    //     }
    // }
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
            while (curr->next != NULL)
            {
                node* tmp = curr;
                curr = curr->next;
                //TODO: Double free aborts code
                free(tmp);
            }
            //free(curr);
        }
    }

    // TODO
    return false;
}

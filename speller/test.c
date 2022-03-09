#include <cs50.h>
#include <stdio.h>
#include <string.h>
//#include <math.h>

// Declare max length of any given dictionary word
#define LENGTH 45

// 1. Create Node object
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Set Estimated Node list length based on amount of given Keys (dictionary words)
const unsigned int N = 2500;

// 2. Create table for nodes
node *table[N];

// 3. Hash Function for finding the index of a Word
unsigned int hash(const char *word)
{
    int ascii = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        ascii += word[i];
    }

    ascii *= strlen(word);
    ascii *= word[0];
    // double new = pow(ascii, strlen(word));
    //return printf("%s -- %i\n\n", word, ascii % 2500);
    return ascii % N;
}

// Load Dictionary words into Hash Table
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
    while (fgets(word, 45, dict))
    {
        // Get hash index of word
        int word_index = hash(word);

        // Populate new node properties
        table[word_index]->word = word;
        //table[word_index]->next = NULL;




    }

    // Allocate Memory for node
    //node *n = malloc(sizeof(node));
    // Fill node with word and next address
    //strcpy(n->word, "hello");
    //n->next = NULL;
    // assign node to linked hashmap spot based on hash function

    return loaded;
}


// Main Execution
int main(void)

{
    //printf("test\n");
    FILE *dict = fopen("dictionaries/large", "r");

    for (int i=0; i<N; i++) {
        printf("%i -- %s\n", i, table[i]->word);
    }

    // READING LINE BY LINE WITH SPECIFIED BUFFER SIZE
    char word[45];
    while (fgets(word, 45, dict))
    {
        hash(word);
        //table[hash(word)] = word;

        if (strlen(word) == 12)
        {
            break;
        }

    }

    fclose(dict);
    return 0;
}

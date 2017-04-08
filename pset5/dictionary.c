/**
* dictionary.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// define trie
typedef struct node
{
    bool is_word;
    struct node *children[27];
}
node;

// the pointer to keep track of the top of the beginning of the trie
node *root; 

//define number of words in dictionary for Load and Size
unsigned int wordsD = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    node *newPointer = root;
    if (root == NULL)
        {
            fprintf(stderr, "Could not allocate memory");
            return 1;
        }
    
    // define an index of the array of characters
    int i = 0;
    
    for (int j = 0; word[j] != '\0'; j++)
    {
        // calculate indexes
        i = (word[j] == 39) ? 0 : tolower(word[j]) - 96;
        
        if (newPointer -> children[i] == NULL)
            return false;
        newPointer = newPointer -> children[i]; 
    }   
    if (newPointer -> is_word == true)
        return true;
    return false;    
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open input file 
    FILE *inFile = fopen(dictionary, "r");
    if (inFile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 1;
    }
    
    // allocate memory for a node and initialise the node
    root = calloc(1, sizeof(node));
    
    // the pointer to a current node
    node *newPointer = root;
    
    // current character
    char trav;
    
    // define an index of the array of characters
    int i = 0;
    
    while (!feof(inFile))
    {
        //load a word    
        while ((trav = fgetc(inFile)) != '\n')
        {
            if (feof(inFile)) 
                break;  
                
            // calculation of the indexes
            i = (trav == 39) ? 0 : trav - 96;
            
            if (newPointer -> children[i] == NULL)
            {
                // allocate memory for a new node and initialise it
                newPointer -> children[i] = calloc(1, sizeof(node));
                if (newPointer -> children[i] == NULL)
                {
                    fprintf(stderr, "Could not allocate memory");
                    return 1;
                }
                
            }
            // move the pointer to a current node
            newPointer = newPointer -> children[i];   
        }    
        newPointer -> is_word = true;
        newPointer = root;
        if (feof(inFile))
            break;
            
        wordsD++;
    }
    fclose(inFile);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordsD;
}

/**
 * Recursion for Unload.
 */
void repeat(node *root)
{
    for (int i = 0; i < 27; i++)
    {
        if (root -> children[i] != NULL )
        {
             repeat(root -> children[i]); 
        }
    }
    free(root);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    repeat(root);
    return true;
}

/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

#include "dictionary.h"
 typedef struct TrieNode
{
    struct TrieNode* children[27];
    bool isLeaf;
}TrieNode;
struct TrieNode* root = NULL;
int dSize=0;

TrieNode* newt()
{
    return (TrieNode*) malloc(sizeof(TrieNode));
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
   TrieNode* next=root;
    
    unsigned int i = 0;
    unsigned int ch=word[i];
    while(ch != '\0')
    {
        ch = word[i];
        
        // If in capital
        if(ch <= 90 && ch >= 65) {
            ch |= 32;
        }
        
        //If in small or apostrophe
        if((ch >= 97 && ch <= 122) || (ch == '\''))
        {
            
            if(ch == '\'')
                ch = 26 + 97;
                
            if(next->children[ch - 97] == NULL)
            {
                return false;
            }
            else
            {
                next = next->children[ch -97];
            }
        }
        
        i++;
    }
    
    return next->isLeaf;
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // opening dictionary
    FILE* d = fopen(dictionary, "r");
    if (d == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    root = newt();
    
    unsigned int ch = 0;
    TrieNode* next=root;
    
    while(ch!=EOF)
    {
        ch=fgetc(d);
        if(ch != '\n' && ch != EOF)
        {
            if(ch == '\'')
                ch = 26 + 97;
                
            if(next->children[ch -97] == NULL)
            {
                next->children[ch - 97] = newt();
            }
            next = next->children[ch - 97];
        }
        // next word
        else if(ch== '\n')
        {
            next->isLeaf = true;
            dSize++;
            next = root;
        }
    }
    
    
    fclose(d);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dSize;
}

void unloadNode(struct TrieNode* next)
{
    // delete nodes in climb-up manner
    for(int i = 0; i < 26; i++)
    {
        if(next->children[i] != NULL)
        {
            unloadNode(next->children[i]);
        }
    }
    

    free(next);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
 
    unloadNode(root);
    return true;
}
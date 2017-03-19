/**
 * crack.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Cracks passwords.
 */
 
#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// constant
const char *SALT = "50";

char key[5];
char *result;
int compareResult;


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage:./crack hash\n");
        return 1;
    }
    
    char letters[53];
    int i, j, k, l;
    for (i = 0; i < 26; i++)
        letters[i] = (char) (i + 65);
    for (i = 0; i < 26; i++)   
        letters[i+26] = (char) (i + 97);
        
    // if the password is one character
    for (i = 0; i < 52; i++) 
    {
        key[0] = letters[i];
        result = crypt(key, SALT);
        compareResult = strcmp(result, argv[1]);
        if (compareResult == 0)
        {
            printf("%s\n", key);
            break;
        }
       
    }        
            
            
    // if the password is two characters
    for (i = 0; i < 52; i++) 
    {
        key[0] = letters[i];
        for (j = 0; j < 52; j++)
        { 
            key[1] = letters[j];
            result = crypt(key, SALT);
            compareResult = strcmp(result, argv[1]);
            if (compareResult == 0)
            {
                printf("%s\n", key);
                break;
            }
        }    
    }        

    // if the password is three characters
    for (i = 0; i < 52; i++) 
    {
        key[0] = letters[i];
        for (j = 0; j < 52; j++)
        {
            key[1] = letters[j];
            for (k = 0; k < 52; k++)
            {
                key[2] = letters[k];
                result = crypt(key, SALT);
                compareResult = strcmp(result, argv[1]);
                if (compareResult == 0)
                {
                    printf("%s\n", key);
                    break;
                }
            }
        }    
    }        

    // if the password is four characters
    for (i = 0; i < 52; i++) 
    {
        key[0] = letters[i];
        for (j = 0; j < 52; j++)
        {
            key[1] = letters[j];
            for (k = 0; k < 52; k++)
            {
                key[2] = letters[k];
                for (l = 0; l < 52; l++)
                {
                    key[3] = letters[l];
                    result = crypt(key, SALT);
                    compareResult = strcmp(result, argv[1]);
                    if (compareResult == 0)
                    {
                        printf("%s\n", key);
                        break;
                    }
                }
            }
        }    
    }        
   return 0;
}    

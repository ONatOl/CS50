/**
 * vigenere.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Encrypts messages using Vigenère’s cipher.
 */
 
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// prototype 
void PrintLetters(char a, char b, int c, int *d);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage:./vigenere key\n");
        return 1;
    }
    
    string k = argv[1];
    for (int j = 0, n = strlen(k); j < n; j++)
    
        if (! isalpha(k[j]))
        {
            printf("Key is a set of characters from A to Z or from a to z\n");
            return 1; 
        }
    
    printf("plaintext:  ");    
    string s = GetString();
    printf("ciphertext: ");
    
    for (int j = 0, n = strlen(k); j < n; j++)
        k[j] = toupper(k[j]);
    int step;    
    int way = 0;    
    for (int i =  0, n = strlen(s); i < n; i++)       
    {
        if (isalpha(s[i]))
            {
                if (isupper(s[i]))
                    step = 65;
                else 
                    step = 97;  
                PrintLetters(s[i], k[way%strlen(k)], step, &way);
            }
        
        else
            printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}  

void PrintLetters(char sf, char kf, int stepf, int *wayf)
{
    printf("%c", (sf - stepf + kf-65) % 26 + stepf);
    (*wayf)++;
}    

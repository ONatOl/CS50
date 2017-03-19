/**
 * caesar.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Encrypts messages using Caesar’s cipher.
 */
 
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// prototype 
void PrintLetters(char a, int b, int c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf(" Usage:./caesar key\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    printf("plaintext:  ");
    string s = GetString();
    printf("ciphertext: ");
    int step;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
                step = 97;
            else 
                step = 65;
            PrintLetters(s[i], k, step);
        }
        else
            printf("%c", s[i]);
    }
    
    printf("\n");
    return 0;
}

void PrintLetters(char sf, int kf, int stepf)
{
    printf("%c", (sf - stepf + kf) % 26 + stepf);
}    

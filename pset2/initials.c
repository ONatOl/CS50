/**
 * initials.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Given a person’s name, prints a person’s initials.
 */
 
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string s = GetString();
    
    if (s[0] != ' ')
        printf("%c", toupper(s[0]));
        
    for (int i = 1, n = strlen(s); i < n; i++)
        if (s[i] != ' ' && s[i-1] == ' ')
            printf("%c", toupper(s[i]));
                        
    printf("\n");
    
}

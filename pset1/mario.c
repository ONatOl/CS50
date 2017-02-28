/**
 * mario.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Prints out a double half-pyramid of a specified height.
 */
 
#include <cs50.h>
#include <stdio.h>

// prototype 
void PrintGrid(int a);

int main(void)
{
    int n;
    do
    {
        printf("Give me an integer from 0 to 23: ");
        n=GetInt();
    }
    while((n <0) || (n>23));
    // pyramid
    for(int i = 0; i < n; i++ )
    {
        for(int j = 0; j < n - i - 1; j++)
            printf(" ");
        PrintGrid(i); 
        printf("  ");
        PrintGrid(i);        
        printf("\n");    
    }
}
void PrintGrid(int ii) 
{
    for(int k = 0; k <= ii; k++)
        printf("#");
}

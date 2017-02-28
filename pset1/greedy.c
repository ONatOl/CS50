/**
 * greedy.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Calculates the minimum number of coins required to give a user change.
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    do
    {
        printf("How much change is owed?\n");
        n = GetFloat();
    }
    while(n < 0);
    float f = n * 100;
    int i = (int) round(f);
    int c = 0;
    
    c = i / 25;
    i = i % 25;
    
    c = c + i / 10;
    i = i % 10;
     
    c = c + i / 5;    
      
    c = c + i%5 / 1;
    
    printf("%d\n", c);
}

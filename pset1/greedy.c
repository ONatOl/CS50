/**
 * greedy.c
 * 
 * Natalya Ostiak
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
    
    int i = (int) round(n * 100);
    int c = 0;
    
    c = i / 25;
    i = i % 25;
    
    c += i / 10;
    i = i % 10;
     
    c += i / 5;    
    
    printf("%d\n", c += i%5);
}

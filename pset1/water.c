/**
 *water.c
 *
 * Natalia Ostiak
 * Technology Nation
 *
 * program reports a user’s water usage
 * converting minutes spent in the shower to bottles of drinking water
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int m;
    do
    {
        printf("Water: ");
        m = GetInt();
    }
    while((m < 0) || (m == 0));
    int b = m * 12;
    printf("Bottles: %i\n", b);
}    

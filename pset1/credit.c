/**
 * credit.c
 * 
 * Natalia Ostiak
 * Technology Nation
 * 
 * Determines whether a provided credit card number is valid
 * according to Luhn’s algorithm.
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long cc_num;
    int d_num = 0;
    int sum_odd = 0;
    int sum_even = 0;
    int sumCheck;
    
    // Get credit card number
    do
    {
        printf("Give me a credit card number: ");
        cc_num = GetLongLong();
    }
    while (cc_num <= 0);
    
    // Define a remainder of the card number
    long long cc_num_D = cc_num;
    
    // Count digits
    do
    {
        d_num++;
        cc_num_D = cc_num_D/10;
    }
    while (cc_num_D > 0);
    
    // Define an array
    int cc_num_A[d_num];
    
    if (d_num!=15 && d_num!=16 && d_num!=13)
    {
        printf("INVALID\n");
        return 0;
    }    
    else
    {
        // Build the reverse array
        for (int i = 0; i < d_num; i++)
        {
            cc_num_A[i] = cc_num % 10;
            cc_num = cc_num / 10;
        }
    }
    
    
    // Luhn’s algorithm
   
    for (int i = 0; i < d_num; i = i + 2)
            sum_odd = sum_odd + cc_num_A[i];
    
    for (int i = 1; i < d_num; i = i + 2)
    {
        int even = cc_num_A[i] * 2;
            
        if (even > 9)
            sum_even = sum_even + even - 9;
        else
            sum_even = sum_even + even;
    }
    
    sumCheck = (sum_odd + sum_even) % 10;
    
    if (sumCheck != 0)
        printf("INVALID\n");
        
    else if (d_num==15 && cc_num_A[d_num-1]==3 && (cc_num_A[d_num-2]==4 || cc_num_A[d_num-2]==7))
            printf("AMEX\n");
        
        else if (d_num==16 && cc_num_A[d_num-1]==5 && (cc_num_A[d_num-2]==1 || cc_num_A[d_num-2]==2 
                           || cc_num_A[d_num-2]==3 || cc_num_A[d_num-2]==4 || cc_num_A[d_num-2]==5))
                printf("MASTERCARD\n");
            
            else if ((d_num==13 || d_num==16) && cc_num_A[d_num-1]==4)
                    printf("VISA\n");
        
                 else
                    printf("INVALID\n");
                    
    return 0;
}

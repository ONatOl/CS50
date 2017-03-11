/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int lower = 0;
    int upper = n - 1;
    while (lower <= upper)
    {
        int mid = lower + (upper - lower)/2;
        if (values[mid] > value)
            upper = mid - 1;
        else
            if (values[mid] < value)
                lower = mid + 1;
            else     
                if (values[mid] == value)
                    return true;
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for(int i = 0; i < n - 1; i++)
    {
        int j;
        int min = i;
        for (j = i + 1; j < n; j++)
            if (values[j] < values[min])
                min = j;
                
        if (min != i) 
        {
            int temp = values[i];
            values[i] = values[j];
            values[j] = temp;
        }   
    }
    return;
}

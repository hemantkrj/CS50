/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
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
    if(value<0)
    return false;
    int l=0,r=n-1,m;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(values[m]==value)
        return true;
        if(values[m]<value)
        l=m+1;
        else
        r=m-1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{  int i;
    for(i=1;i<n;i++)
    {
        int j=i-1;
        int key=values[i];
        while(j>=0&&key<values[j])
        {
            values[j+1]=values[j];
            j--;
        }
        values[j+1]=key;
        
    }
    return;
}
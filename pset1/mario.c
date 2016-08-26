#include <stdio.h>
#include<cs50.h>
int main(void)
{
    int n,i,j,k;
    do
    {
        printf("Height: ");
    n=GetInt();
    }
    while(n<0||n>23);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        printf(" ");
        for(k=0;k<i+2;k++)
        printf("#");
        printf("\n");
    }
}
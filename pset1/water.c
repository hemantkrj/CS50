#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int a;
    printf("minutes: ");
    a=GetInt();
    printf("bottles: %d\n",a*12);
}
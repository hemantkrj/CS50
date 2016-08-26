
#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    float f;
    do
    {
      printf("O hai! How much change is owed?\n");
      f=GetFloat();
    }
    while(f<=0);
    
    int n=round(f*100);
    int c=0;
    if(n>=25)
    {
        c=c+n/25;
        n=n%25;
    }
    if(n>=10)
    {
        c=c+n/10;
        n=n%10;
    }
    if(n>=5)
    {
        c=c+n/5;
        n=n%5;
    }
    if(n>=1)
    {
        c=c+n;
    }
    printf("%d\n",c);
}

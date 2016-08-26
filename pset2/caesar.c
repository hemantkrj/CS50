#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,string args[])
{    
    if(argc>2)
    return 1;
    else if(argc<2)
    {
    printf("Usage: /home/cs50/pset2/caesar <key>\n");
    return 1;
    }
    else
    {
    string p=GetString(); 
    int k=atoi(args[1]);
    int i,n;
for (i = 0, n = strlen(p); i < n; i++)
   {   
     if(p[i]>64&&p[i]<91)
   {
   	 p[i]=(p[i]-65+k)%26;
     p[i]=p[i]+65;
   }
    if(p[i]>96&&p[i]<123)
  {
   	 p[i]=(p[i]-97+k)%26;
     p[i]=p[i]+97;
   }
   }
   printf("%s\n",p);
   return 0;
    }
}
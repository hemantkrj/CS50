#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,string args[])
{    
    if(argc>2)
    {
    printf("Usage: /home/cs50/pset2/caesar <key>\n");    
    return 1;
    }
    else if(argc<2)
    {
    printf("Usage: /home/cs50/pset2/caesar <key>\n");
    return 1;
    }
    else
    {
     
    string k=args[1];
    int m;
    for(m=0;m<strlen(k);m++)
    {
        if(!(k[m]>64&&k[m]<91)&&!(k[m]>96&&k[m]<123))
        {
            printf("Keyword must only contain letters A-Z and a-z\n");
            return 1;
        }
    }
    string p=GetString();
    int i,n;
    n=strlen(p);
    int kl=strlen(k);
    char key[n];
    for(i=0;i<n;i++)
    {
        key[i]=k[i%kl];
    }
    int j;
    int x;
   // printf("%s",key);
for (i = 0,j=0; i < n; i++)
   {   
     if(p[i]>64&&p[i]<91)
   {  x=((key[j]>64&&key[j]<91)?(key[j]-65):(key[j]-97));
   	 p[i]=(p[i]-65+x)%26;
     p[i]=p[i]+65;
     j++;
   }
    else if(p[i]>96&&p[i]<123)
  {   x=((key[j]>64&&key[j]<91)?(key[j]-65):(key[j]-97));
   	 p[i]=(p[i]-97+x)%26;
     p[i]=p[i]+97;
     j++;
   }
   else
      continue;
   }
   printf("%s\n",p);
   return 0;
    }
}
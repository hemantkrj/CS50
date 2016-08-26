#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main()
{
    string s=GetString();
    int i,n;
    if(s!=NULL)
	{
	    if(s[0]>96&&s[0]<123)
             printf("%c",s[0]-32);
	    else if(s[0]>64&&s[0]<91)
	         printf("%c",s[0]);
	
    for(i=1,n=strlen(s);i<n;i++)
    {
        if(s[i]==' ')
        {
             if(s[i+1]>96&&s[i+1]<123)
               
               {
               printf("%c",s[i+1]-32);
               }
	         else if(s[i+1]>64&&s[i+1]<91)
	           printf("%c",s[i+1]);
        }
    }
	   printf("\n"); 
	}
    
    
}
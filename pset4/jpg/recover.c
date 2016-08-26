/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
typedef uint8_t byte;

#define BLOCK_SIZE 512
int main(int argc, char* argv[])
{
    char outfile[8];
    FILE *outptr;
    byte sign0[4]={0xff, 0xd8, 0xff, 0xe0};
    byte sign1[4]={0xff, 0xd8, 0xff, 0xe1};
   byte sign2[4]={0xff, 0xd8, 0xff, 0xe2};
    byte sign3[4]={0xff, 0xd8, 0xff, 0xe3};
    byte sign4[4]={0xff, 0xd8, 0xff, 0xe4};
    byte sign5[4]={0xff, 0xd8, 0xff, 0xe5};
    byte sign6[4]={0xff, 0xd8, 0xff, 0xe6};
    byte sign7[4]={0xff, 0xd8, 0xff, 0xe7};
    byte sign8[4]={0xff, 0xd8, 0xff, 0xe8};
    byte sign9[4]={0xff, 0xd8, 0xff, 0xe9};
    byte signa[4]={0xff, 0xd8, 0xff, 0xea};
    byte signb[4]={0xff, 0xd8, 0xff, 0xeb};
    byte signc[4]={0xff, 0xd8, 0xff, 0xec};
    byte signd[4]={0xff, 0xd8, 0xff, 0xed};
    byte signe[4]={0xff, 0xd8, 0xff, 0xee};
    byte signf[4]={0xff, 0xd8, 0xff, 0xef};
    byte buffer[512];
    int img=0;
    
    FILE* card=fopen("card.raw","r");
    if(card==NULL)
    {
        printf("Could not open raw file\n");
        return 1;
    }
    int isopen=0;      
while (!feof(card))
        {
              int i;
              int count = 0;    

              fread(buffer, sizeof(buffer[0])* BLOCK_SIZE,1, card);    

              
              for (i = 0; i < 4; i++)
                  if (buffer[i] == sign0[i] || buffer[i] == sign1[i]||buffer[i] == sign2[i]||buffer[i] == sign3[i]||buffer[i] == sign4[i]||buffer[i] == sign5[i]||buffer[i] == sign6[i]||buffer[i] == sign7[i]||buffer[i] == sign8[i]||buffer[i] == sign9[i]||buffer[i] == signa[i]||buffer[i] == signb[i]||buffer[i] == signc[i]||buffer[i] == signd[i]||buffer[i] == signe[i]||buffer[i] == signf[i])
                     count++;
           
                
              if (count == 4)
              {
                        //if already open,its mark of end of previous,so close previous
                        if (isopen == 1)
                            fclose(outptr);
                       //name image
                        sprintf(outfile, "%.3d.jpg", img);
                        outptr = fopen(outfile, "w");
                                if (outptr == NULL)
                                {
                                            printf("couldn't write\n");
                                            return 1;
                                }
                        img++; 
                       
                      fwrite(buffer, sizeof(buffer[0])*BLOCK_SIZE,1, outptr);
                isopen = 1;    
              }

              
              //If already open,its part of previous image,so write 
              else if (isopen == 1)
                        fwrite(buffer, sizeof(buffer[0])*BLOCK_SIZE,1, outptr);

            
        }
        fclose(outptr);
        fclose(card);
        //printf("recovered");
        return 0;
    }

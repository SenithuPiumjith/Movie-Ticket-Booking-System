#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

int readInt(const char *prompt,int min,int max)
{
    char line[128];
    int value;

    while(1)
    {
        printf("%s",prompt);

        if(fgets(line,sizeof(line),stdin)==NULL)
        {
            exit(0);
        }

        if(sscanf(line,"%d",&value)==1 &&
           value>=min &&
           value<=max)
        {
            return value;
        }

        printf("Invalid input.\n");
    }
}

void readLine(const char *prompt,char *buffer,int size)
{
    printf("%s",prompt);

    if(fgets(buffer,size,stdin)==NULL)
    {
        exit(0);
    }

    buffer[strcspn(buffer,"\n")]='\0';
}

char readChar(const char *prompt)
{
    char line[32];

    while(1)
    {
        printf("%s",prompt);

        if(fgets(line,sizeof(line),stdin)==NULL)
        {
            exit(0);
        }

        if(line[0]!='\n')
            return line[0];

        printf("Invalid input.\n");
    }
}

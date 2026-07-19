#include <stdio.h>
#include <string.h>
#include "input.h"

int readInt(const char *prompt, int min, int max)
{
    int value;

    while (1)
    {
        printf("%s", prompt);

        scanf("%d", &value);

        while(getchar()!='\n');

        if(value>=min && value<=max)
            return value;

        printf("Invalid input.\n");
    }
}

void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);

    fgets(buffer,size,stdin);

    buffer[strcspn(buffer,"\n")] = '\0';
}

char readChar(const char *prompt)
{
    char ch;

    printf("%s",prompt);

    scanf(" %c",&ch);

    while(getchar()!='\n');

    return ch;
}

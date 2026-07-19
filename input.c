#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

int readInt(const char *prompt, int min, int max) {
    char line[128];
    int  value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(line, sizeof(line), stdin)) {
            if (feof(stdin)) {
                printf("\nNo more input available. Exiting.\n");
                exit(0);
            }
            clearerr(stdin);
            continue;
        }

        if (sscanf(line, "%d", &value) == 1 && value >= min && value <= max) {
            return value;
        }

        printf("Invalid input. Please enter a whole number between %d and %d.\n",
               min, max);
    }
}

void readLine(const char *prompt, char *buffer, int bufSize) {
    printf("%s", prompt);

    if (fgets(buffer, bufSize, stdin) == NULL) {
        if (feof(stdin)) {
            printf("\nNo more input available. Exiting.\n");
            exit(0);
        }
        clearerr(stdin);
        buffer[0] = '\0';
        return;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

char readChar(const char *prompt) {
    char line[128];

    while (1) {
        printf("%s", prompt);

        if (!fgets(line, sizeof(line), stdin)) {
            if (feof(stdin)) {
                printf("\nNo more input available. Exiting.\n");
                exit(0);
            }
            clearerr(stdin);
            continue;
        }

        for (size_t i = 0; line[i] != '\0'; i++) {
            if (!isspace((unsigned char) line[i])) {
                return line[i];
            }
        }

        printf("Invalid input. Please enter a letter.\n");
    }
}

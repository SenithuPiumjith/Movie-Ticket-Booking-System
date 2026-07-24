#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "config.h"
#include "input.h"

int authenticateAdmin(void) {
    char username[MAX_NAME_LEN];
    char password[MAX_NAME_LEN];

    for (int attempt = 1; attempt <= MAX_LOGIN_ATTEMPTS; attempt++) {
        readLine("Admin username (or press Enter to cancel and go back): ", username, sizeof(username));

        if (username[0] == '\0') {
            printf("\nLogin cancelled.\n");
            return 0;
        }

        readLine("Admin password: ", password, sizeof(password));

        if (strcmp(username, ADMIN_USERNAME) == 0 &&
            strcmp(password, ADMIN_PASSWORD) == 0) {
            printf("\nLogin successful.\n");
            return 1;
        }

        printf("Incorrect username or password. (attempt %d of %d)\n",
               attempt, MAX_LOGIN_ATTEMPTS);
    }

    printf("\nToo many failed attempts.\n");
    return 0;
}

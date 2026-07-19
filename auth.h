#ifndef AUTH_H
#define AUTH_H

/*
 * Prompts for an admin username and password (hardcoded credentials,
 * see config.h) and gives up to MAX_LOGIN_ATTEMPTS tries.
 * Returns 1 if login succeeds, 0 if all attempts are used up.
 */
int authenticateAdmin(void);

#endif /* AUTH_H */

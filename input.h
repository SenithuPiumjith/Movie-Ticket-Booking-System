#ifndef INPUT_H
#define INPUT_H

// Repeats the prompt until the user enters an integer in [min, max].
int readInt(const char *prompt, int min, int max);

// Reads a full line of text (e.g. a name) into buffer, stripping '\n'.
void readLine(const char *prompt, char *buffer, int bufSize);

// Reads a single non-whitespace character (e.g. a row letter).
char readChar(const char *prompt);

#endif /* INPUT_H */

#include <string.h>
#include <ctype.h>
#include "cipher.h"

// Initialize the alphabet queue A-Z
void initializeQueue(char letters[], int *front, int *rear) {
    *front = 0;
    *rear = ALPHABET - 1;
    for (int i = 0; i < ALPHABET; i++) {
        letters[i] = 'A' + i;
    }
}

// Find the index of a letter
int getLetterIndex(char letters[], char letter) {
    for (int i = 0; i < ALPHABET; i++) {
        if (letters[i] == letter) {
            return i;
        }
    }
    return -1;
}

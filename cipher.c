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

// Find the index of a letter in the alphabet
int getLetterIndex(char letters[], char letter) {
    for (int i = 0; i < ALPHABET; i++) {
        if (letters[i] == letter) {
            return i;
        }
    }
    return -1;
}
// Caesar encryption
void encryptText(char letters[], const char *inputText, char *encryptedText, int shiftKey) {
    int length = ALPHABET;
    for (int i = 0; inputText[i] != '\0'; i++) {
        char currentChar = toupper(inputText[i]);
        if (isalpha(currentChar)) {
            int index = getLetterIndex(letters, currentChar);
            int newIndex = (index + shiftKey) % length;
            encryptedText[i] = isupper(inputText[i]) ? letters[newIndex] : tolower(letters[newIndex]);
        } else {
            encryptedText[i] = inputText[i]; // preserve non-letter characters
        }
    }
    encryptedText[strlen(inputText)] = '\0';
}

// Caesar decryption
void decryptText(char letters[], const char *encryptedText, char *decryptedText, int shiftKey) {
    int length = ALPHABET;
    for (int i = 0; encryptedText[i] != '\0'; i++) {
        char currentChar = toupper(encryptedText[i]);
        if (isalpha(currentChar)) {
            int index = getLetterIndex(letters, currentChar);
            int originalIndex = (index - shiftKey + length) % length;
            decryptedText[i] = isupper(encryptedText[i]) ? letters[originalIndex] : tolower(letters[originalIndex]);
        } else {
            decryptedText[i] = encryptedText[i]; // preserve non-letter characters
        }
    }
    decryptedText[strlen(encryptedText)] = '\0';
}
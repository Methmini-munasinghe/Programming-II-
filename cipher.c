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
// Caesar encryption
void encryptText(char letters[], const char *inputText, char *encryptedText, int shiftKey) {
    int length = ALPHABET;
    for (int i = 0; inputText[i] != '\0'; i++) {
        char currentChar = inputText[i];
        if (isalpha(currentChar)) {
            char upper = toupper(currentChar);
            int index = getLetterIndex(letters, upper);
            int shiftedIndex = (index + shiftKey + length) % length;
            encryptedText[i] = isupper(currentChar) ? letters[shiftedIndex] : tolower(letters[shiftedIndex]);
        } else {
            encryptedText[i] = currentChar;
        }
    }
    encryptedText[strlen(inputText)]='\0';
}
// Caesar decryption
void decryptText(char letters[], const char *encryptedText, char *decryptedText, int shiftKey) {
    int length = ALPHABET;
    for (int i = 0; encryptedText[i] != '\0'; i++) {
        char currentChar = encryptedText[i];
        if (isalpha(currentChar)) {
            char upper = toupper(currentChar);
            int index = getLetterIndex(letters, upper);
            int originalIndex = (index - shiftKey + length) % length;
            decryptedText[i] = isupper(currentChar) ? letters[originalIndex] : tolower(letters[originalIndex]);
        } else {
            decryptedText[i] = currentChar;
        }
    }
    decryptedText[strlen(encryptedText)] = '\0';
}
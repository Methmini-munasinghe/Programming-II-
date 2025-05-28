#ifndef CIPHER_H_INCLUDED
#define CIPHER_H_INCLUDED

#define ALPHABET 26

// Function declarations using array instead of struct
void initializeQueue(char letters[], int *front, int *rear);
int getLetterIndex(char letters[], char letter);
void encryptText(char letters[], const char *inputText, char *encryptedText, int shiftKey);
void decryptText(char letters[], const char *encryptedText, char *decryptedText, int shiftKey);

#endif // CIPHER_H_INCLUDED


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
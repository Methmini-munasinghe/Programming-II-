#include <stdio.h>
#include <string.h>
#include "cipher.h"

int main() {
    char letters[ALPHABET];
    int front, rear;
    initializeQueue(letters, &front, &rear);

    char choice;
    char original[100], encrypted[100], decrypted[100];
    int shift;

    printf("Do you want to Encrypt (E) or Decrypt (D)? ");
    scanf(" %c", &choice);  // Leading space clears newline
    getchar(); // clears the newline from buffer after scanf

    if (choice == 'E' || choice == 'e') {
        printf("Enter your message to encrypt: ");
        fgets(original, sizeof(original), stdin);
        original[strcspn(original, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &shift);

        encryptText(letters, original, encrypted, shift);
        printf("Encrypted message: %s\n", encrypted);
    }
    else if (choice == 'D' || choice == 'd') {
        printf("Enter your message to decrypt: ");
        fgets(original, sizeof(original), stdin);//Gets input string and removes trailing newline.
        original[strcspn(original, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &shift);

        decryptText(letters, original, decrypted, shift);
        printf("Decrypted message: %s\n", decrypted);
    }
    else {
        printf("Invalid choice! Please enter E or D.\n");
    }

    return 0;
}
/*Caesar Cipher shifts each letter by a fixed number of positions.

For example: with shift = 3, A becomes D, B becomes E, etc.

The queue initialized in letters[] holds the alphabet to assist this shifting.

Encryption shifts forward, while decryption shifts backward using the same shift value.*/

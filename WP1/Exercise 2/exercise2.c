//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 1
//Submission number: 2763534813
#include <stdio.h>
//Exercise 2

int main() {
    // Create character array and key variable.
    char message[100], ch;
    int i, key;
    do{
    printf("Enter a message to encrypt: ");
    //Read character array.
        scanf("%s", message);
    //gets(message);
    // Enter the key that will determine how many letters will be shifted.
    printf("Enter key: ");
    scanf("%d", &key);
    //For every character in the array, execute the "IF" statement.
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        //If lowercase.
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
            //If capital.
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    //Print the encrypted message.
    printf("Encrypted message: %s \n", message);
} while (message[1] != EOF);

        return 0;
}
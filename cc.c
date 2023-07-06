#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void enc(char* text, int sf) {
    for(int i = 0; text[i] != '\0'; ++i) {
        if(islower(text[i])) {  // To check if the character is a lowercase letter
            text[i] = (text[i] - 'a' + sf) % 26 + 'a';  // Apply the encryption formula
        }
        if(isupper(text[i])) {  // To check if the character is an uppercase letter
            text[i] = (text[i] - 'A' + sf) % 26 + 'A';
        }
        if(isdigit(text[i])) {  // To check if the character is a digit
            text[i] = (text[i] - '0' + sf) % 10 + '0';
        }
    }
}

void dec(char* text, int sf) {
    for(int i = 0; text[i] != '\0'; ++i) {
        if(islower(text[i])) {
            text[i] = (text[i] - 'a' - sf + 26) % 26 + 'a';  // Apply the decryption formula
        }
        if(isupper(text[i])) {
            text[i] = (text[i] - 'A' - sf + 26) % 26 + 'A';
        }
        if(isdigit(text[i])) {
            text[i] = (text[i] - '0' - sf + 10) % 10 + '0';
        }
    }
}

int main() {
   char text[200];
   int sf, choice;  // shift factor

   printf("Enter 1 to decode and 2 to encode: ");
   scanf("%d", &choice);  // Read the choice from the user (1 for decoding, 2 for encoding)
   printf("Enter the string: ");
   scanf("%s", text);  // Read the string input from the user
   printf("Enter the shift-factor: ");
   scanf("%d", &sf);

   if(choice == 1)
       dec(text, sf);  // Call the dec function to decode the string
   else
       enc(text, sf);  // Call the enc function to encode the string

   printf("The message is %s\n", text);  // Print the resulting message
   return 0;
}

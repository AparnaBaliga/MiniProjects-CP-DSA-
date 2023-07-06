#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void enc(char* text, int sf) {
    for(int i = 0; text[i] != '\0'; ++i) {
        if(islower(text[i])) {
            text[i] = (text[i] - 'a' + sf) % 26 + 'a';
        }
        if(isupper(text[i])) {
            text[i] = (text[i] - 'A' + sf) % 26 + 'A';
        }
        if(isdigit(text[i])) {
            text[i] = (text[i] - '0' + sf) % 10 + '0';
        }
    }
}

void dec(char* text, int sf) {
    for(int i = 0; text[i] != '\0'; ++i) {
        if(islower(text[i])) {
            text[i] = (text[i] - 'a' - sf + 26) % 26 + 'a';
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
   int sf, choice;  //shift factor

   printf("Enter 1 to decode and 2 to encode: ");
   scanf("%d", &choice);
   printf("Enter the string: ");
   scanf("%s", text);
   printf("Enter the shift-factor: ");
   scanf("%d", &sf);

   if(choice == 1)
       dec(text, sf);
   else
       enc(text, sf);

   printf("The message is %s\n", text);
   return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, l, num, s;
    srand(time(NULL));
    char numbers[] = "0123456789";
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char symbols[] = "!@#$^&*?";
    char password[n+1];


    printf("WELCOME TO PASSWORD GENERATOR !!\n");
    printf("Enter the length of the password to be generated:");
    scanf("%d", &n);
    printf("How many letters do you want? ");
    scanf("%d", &l);
    printf("How many numbers do you want? ");
    scanf("%d", &num);
    printf("How many symbols do you want? ");
    scanf("%d", &s);

    if ((l + num + s > n)||( l + num + s < n )) {
        printf("Please enter the numbers such that it meets the length mentioned!!!.\n");
        return 1;
    }
for(int i=0;i<n;i++)
{
    for (int j = 0; j < num; j++) {
        password[i++] = numbers[rand() % 10];
    }

    for (int j = 0; j < l; j++) {
        password[i++] = letters[rand() % 26];
    }

    for (int j = 0; j < s; j++) {
        password[i++] = symbols[rand() % 8];
    }
}
    password[n] = '\0';

    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("Generated password: %s\n", password);

    return 0;
}

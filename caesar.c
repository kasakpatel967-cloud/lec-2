#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if only one command-line argument is given
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if key contains only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert key from string to integer
    int key = atoi(argv[1]);

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt each character
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];

        // For uppercase letters
        if (isupper(ch))
        {
            char cipher = ((ch - 'A' + key) % 26) + 'A';
            printf("%c", cipher);
        }

        // For lowercase letters
        else if (islower(ch))
        {
            char cipher = ((ch - 'a' + key) % 26) + 'a';
            printf("%c", cipher);
        }

        // Non-alphabetical characters remain unchanged
        else
        {
            printf("%c", ch);
        }
    }

    printf("\n");

    return 0;
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check if key is provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Check if key has 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check if all characters are alphabetic
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    // Check for repeated characters
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char ch = plaintext[i];

        // Uppercase letters
        if (isupper(ch))
        {
            int index = ch - 'A';
            printf("%c", toupper(key[index]));
        }

        // Lowercase letters
        else if (islower(ch))
        {
            int index = ch - 'a';
            printf("%c", tolower(key[index]));
        }

        // Non-alphabetic characters remain unchanged
        else
        {
            printf("%c", ch);
        }
    }

    printf("\n");

    return 0;
}

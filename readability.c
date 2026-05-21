#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get text input from user
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Count letters, words, and sentences
    for (int i = 0; i < strlen(text); i++)
    {
        // Count letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Count words
        if (text[i] == ' ')
        {
            words++;
        }

        // Count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate average letters per 100 words
    float L = ((float) letters / words) * 100;

    // Calculate average sentences per 100 words
    float S = ((float) sentences / words) * 100;

    // Coleman-Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round to nearest whole number
    int grade = round(index);

    // Print grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

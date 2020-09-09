#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string sample);
int count_words(string sample);
int count_sentences(string sample);

int main(void)
{
    //Prompt user for input
    string sample = get_string("Text: ");
    
    //Count total number of letters
    int num_letters = count_letters(sample);

    //Count total number of words
    int num_words = count_words(sample);

    //Count total number of sentances
    int num_sentences = count_sentences(sample);

    //Compute L and S
    float l = ((float)num_letters / (float)num_words) * 100;
    float s = ((float)num_sentences / (float)num_words) * 100;

    //Compute Colman Liau Index value.
    float cl_index = 0.0588 * l - 0.296 * s - 15.8;

    //Print reading level.
    if (cl_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cl_index >= 1 && cl_index < 16)
    {
        printf("Grade %i\n", (int) round(cl_index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string sample)
{
    int count = 0;

    for (int i = 0; i < strlen(sample); i++)
    {
        if (isalpha(sample[i])) //Check if char is an alphabetical charachter.
        {
            count++;
        }
    }
    return count;
}

int count_words(string sample)
{
    int count = 0;

    for (int i = 0; i < strlen(sample); i++)
    {
        if (sample[i] == 32) //Check if char is a space.
        {
            count++;
        }
    }
    count++; //Accounts for last word that has a period but no space after it.
    return count;
}

int count_sentences(string sample)
{
    int count = 0;

    for (int i = 0; i < strlen(sample); i++)
    {
        if (sample[i] == 33 || sample[i] == 46 || sample[i] == 63) //Check if char is a "!"", ".", or "?".
        {
            count++;
        }
    }
    return count;
}

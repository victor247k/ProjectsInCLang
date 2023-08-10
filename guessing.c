#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 7

// define the group of quote and author struct
typedef struct
{
    char* quote;
    char* author;
} pair;

// deffine an array of the group
pair quotes[ARRAY_SIZE];

void set_quotes(void);
bool in_array(int arr[], int n, int lenght);

int main(void)
{
    // set up the game

    // set each group
    set_quotes();

    int score = 0;

    // print the rules of the game
    printf("\n\n               Welcome to this guessing game!\n\nWho said it: Kanye or Hitler?\n\nIn this game you have to guess if the quote that's going to appear is either said by Kanye West or Adolf Hitler\n\n");
    // how to play
    printf("How to play:\ntype [h/k] if you think if [H]Hitler or [K]Kanye West said the quote.\n");

    // keep track of the printed quotes
    int idx[ARRAY_SIZE];

    // print the quote
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // randomize the quotes
        do
        {
            idx[i] = rand() % 7;
        }
        while(/*the index is not already in the array*/in_array(idx, idx[i], i + 1));

        // print quote
        printf("\nQuote: %s\n\n", quotes[idx[i]].quote);

        // get user input
        char answer;
        do
        {
            printf("Who said it: ");
            scanf(" %c", &answer);
            answer = tolower(answer);
        }
        while ((answer  != 'k' && answer != 'h') || !isalpha(answer));

        // check user input

        // if they guess right add to the points
        if (tolower(answer) == tolower(quotes[idx[i]].author[0]))
        {
            score++;
            printf("\nYou are correct!\n+ 1 points\n\n");
        }
        // else display the right answer
        else 
        {
            printf("\nWrong!\nThe corect answer is: %s\n\n", quotes[idx[i]].author);
        }
        printf("######################################################\n");

    }

    // print results

    printf("That were all of the quotes.\nYour score is: %i\nThanks for playing!\n", score);

    return 0;
}

void set_quotes(void)
{
    quotes[0].quote = "When a man is starving in the streets he is not thinking of bread and water but of caviar and champagne.";
    quotes[0].author = "Hitler";

    quotes[1].quote = "If today I stand here as a revolutionary, it is as a revolutionary against the Revolution.";
    quotes[1].author = "Hitler";

    quotes[2].quote = "I might have to go back to war, I just might have to.";
    quotes[2].author = "Kanye";

    quotes[3].quote = "Nothing in life is promised except death.";
    quotes[3].author = "Kanye";

    quotes[4].quote = "I realize that my place and position in history is that I will go down as the voice of this generation, of this decade, I will be the loudest voice..";
    quotes[4].author = "Kanye";

    quotes[5].quote = "Who says I am not under the special protection of God?";
    quotes[5].author = "Hitler";

    quotes[6].quote = "I can design something for Obama to go to the club in.";
    quotes[6].author = "Hitler";

    return;
}

bool in_array(int arr[], int n, int lenght)
{
    // check array
    for (int i = 0; i < lenght; i++)
    {
        // if it is return true
        if (i == lenght - 1)
            continue;
        if (n == arr[i])
            return true;
    }

    // if there isnt return false
    return false;
}
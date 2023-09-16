#include<stdio.h>
#include<ctype.h>
#include<string.h>

void how_to_play(char answer);

void how_to_play(char answer)
{
    if (tolower(answer) == 'y')
    {
        printf("-------\n");
        printf("How to play this game!\n");
        printf("There are 9 slots, and each you can choose only 3 slots. You cannot see the numbers inside the selected slots. ");
        printf("Who is with the highest total sum will win that round, and must win 2 out of 3 rounds to conclude the game.");
        printf("\n-------\n");
    }
}

int main()
{
    char how_to;
    char player1[10], player2[10];

    printf("Do you want to know how to play this game?\n(Please answer yes/no)\n");
    scanf("%c", &how_to);
    how_to_play(how_to);

    printf("Please enter your name.\n(character can not longer than 10 characer)\n");
    printf("Player1 : ");
    scanf(" %[^\n]", &player1);
    printf("Player2 : ");
    scanf(" %[^\n]", &player2);

    
}

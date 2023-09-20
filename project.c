#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h>

void how_to_play(char answer);
int random_num();

void how_to_play(char answer)
{
    if (tolower(answer) == 'y')
    {
        printf("-------\n");
        printf("How to play this game!\n");
        printf("There are 9 slots, number in range is 0-10 and you can choose only 3 slots. You cannot see the numbers inside the selected slots. ");
        printf("Who is with the highest total sum will win that round, and must win 2 out of 3 rounds to conclude the game.\n");
        printf("And of course, we have a special rule. At the beginning of the game, there will be a random ability assigned to each player to help increase or decrease the numbers of the opponent. Plus, there's also the option to steal abilities.");
        printf("\n-------\n");
    }
}

int random_num()
{
    return rand() % 10;
}

int main()
{
    char how_to;
    char player1[10], player2[10];
    int number[10];
    unsigned int seed;

    printf("Do you want to know how to play this game?\n(Please answer y/n)\n");
    scanf("%c", &how_to);
    how_to_play(how_to);

    printf("Please enter your name.\n(character can not longer than 10 characer)\n");
    printf("Player1 : ");
    scanf(" %[^\n]", player1);
    printf("Player2 : ");
    scanf(" %[^\n]", player2);

    printf("Input your favourtie number for luck!!!\n");
    printf("(Please input only integer.)\n");
    scanf(" %u", &seed);

    for (int i=0; i<10; i++)
    {
        srand(seed++);
        number[i] = random_num();
    }
}

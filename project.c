#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h>
#include<time.h>

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
    static int initialized = 0;
    
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    
    return rand() % 10;
}

int main()
{
    char how_to;
    char player1[10], player2[10];
    int number[10];
    int count1=0, count2=0;
    const char *ability[3] = {"Increase your score ", "Deducting points from the opposing player ", "Stealing abilities"};

    printf("Do you want to know how to play this game?\n(Please answer y/n)\n");
    scanf("%c", &how_to);
    how_to_play(how_to);

    printf("Please enter your name.\n(character can not longer than 10 characer.)\n");
    printf("Player1 : ");
    scanf(" %[^\n]", player1);
    printf("Player2 : ");
    scanf(" %[^\n]", player2);

    printf("It's time to random ability!\n");
    char *abi1 = ability[random_num() % 3];
    int p1 = (random_num() % 4) + 1;
    char *abi2 = ability[(random_num() + 1) % 3];
    int p2 = (random_num() % 4) + 1;
    if (strcmp(abi1, "Stealing abilities") == 0)
    {
        printf("Player1 your ability is Stealing abilities\n");
        count1++;
    }
    else if (count1 == 0)
        printf("Player1 your ability is %s (%d)\n", abi1, p1);
    if (strcmp(abi2, "Stealing abilities") == 0)
    {
        printf("Player2 your ability is Stealing abilities\n");
        count2++;
    }
    else if (count2 == 0)
        printf("Player2 your ability is %s (%d)\n", abi2, p2);
    

    for (int i=0; i<3; i++)
    {
        for (int i=0; i<10; i++)
        {
            number[i] = random_num();
        }
    }
}

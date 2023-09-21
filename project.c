#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h>
#include<time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void how_to_play(char answer);
int random_num();

struct player
{
    char name[10];
    char *abil;
    int winscore;
    int totalnumber;
};

void how_to_play(char answer)
{
    if (tolower(answer) == 'y')
    {
        printf("-------\n");
        printf("How to play this game!\n");
        printf("There are 9 slots, number in range are 0-10 and you can choose only 3 slots. You cannot see the numbers inside the selected slots. ");
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
    char how_to, remem1, remem2, remem[100];
    struct player player[2];
    int number[10];
    int count1=0, count2=0;
    char *ability[3] = {"Increase your score ", "Deducting points from the opposing player ", "Stealing abilities"};

    printf("Do you want to know how to play this game?\n(Please answer y/n)\n");
    scanf("%c", &how_to);
    how_to_play(how_to);

    printf("Please enter your name.\n(character can not longer than 10 characer.)\n");
    printf("Player1 : ");
    scanf(" %[^\n]", &player[0].name);
    printf("Player2 : ");
    scanf(" %[^\n]", &player[1].name);

    printf("It's time to random ability!\n");
    player[0].abil = ability[random_num() % 3];
    int p1 = (random_num() % 4) + 1;
    player[1].abil = ability[(random_num() + 1) % 3];
    int p2 = (random_num() % 4) + 1;
    printf("From now on, no other player should see your abilities. Ready or not?\n");
    printf("Please type something to confirm.\n");
    scanf(" %[^\n]", remem);
    system(CLEAR);
    if (strcmp(player[0].abil, "Stealing abilities") == 0)
    {
        printf("Player1 your ability is Stealing abilities\n");
        count1++;
    }
    else if (count1 == 0)
        printf("Player1 your ability is %s (%d)\n", player[0].abil, p1);
    printf("If you've memorized the abilities, please type y\n");
    scanf(" %c", &remem1);
    system(CLEAR);
    if (strcmp(player[1].abil, "Stealing abilities") == 0)
    {
        printf("Player2 your ability is Stealing abilities\n");
        count2++;
    }
    else if (count2 == 0)
        printf("Player2 your ability is %s (%d)\n", player[1].abil, p2);
    printf("If you've memorized the abilities, please type y\n");
    system(CLEAR);
    

    for (int i=0; i<3; i++)
    {
        for (int i=0; i<10; i++)
        {
            number[i] = random_num();
        }
    }

    return 0;
}

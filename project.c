#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void how_to_play(char answer);
int random_num();
void mark_choose(int number, char set[]);
int check_choose(int num, int number[], int round);

struct player
{
    char *abil;
    int point_abi;
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
        printf("And of course, we have a special rule. At the beginning of the game, there will be a random ability assigned to each player to help increase your number or decrease the numbers of the opponent.");
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

int check_choose(int num, int number[], int round)
{
    int numbing, count=0;
    if (round == 0)
        return num;
    else
    {
        for (int i=0; i<round; i++)
        {
            if(number[i] == num)
            {
                printf("Please choose another number.\n");
                scanf("%d", &numbing);
                return check_choose(numbing, number, round);
            }
            else count++;
        }
        if (count == round)
            return num;
    }
}

void mark_choose(int number, char set[])
{
    for (int i = 0; i < 41; i++)
    {
        if (set[i] == number + '0')
        {
            set[i] = 'X';
            break;
        }
    }
}

void scores(struct player player[], int who) //not confidents it correct test another day
{
    if (who == 1)
    {
        if (strcmp(player[0].abil, "Increase your score") == 0)
            player[0].totalnumber += player[0].point_abi;
        else if (strcmp(player[0].abil, "Deducting points from the opposing player") == 0)
            player[1].totalnumber -= player[0].point_abi;
    }
    else if (who == 2)
    {
        if (strcmp(player[1].abil, "Increase your score") == 0)
            player[1].totalnumber += player[1].point_abi;
        else if (strcmp(player[1].abil, "Deducting points from the opposing player") == 0)
            player[0].totalnumber -= player[1].point_abi;
    }
}

void winner(struct player player[])
{
    if (player[0].totalnumber > player[1].totalnumber)
    {
        player[0].winscore++;
        printf("%s win\n", player[0].name);
    }
    else if (player[1].totalnumber > player[0].totalnumber)
    {
        player[1].winscore++;
        printf("%s win\n", player[1].name);
    }
    else printf("draw...\n");
}

int main()
{
    char how_to, remem1, remem2, remem[100], name1[10], name2[10];
    struct player player[2];
    int number[6];
    int round=0;
    char *ability[2] = {"Increase your score", "Deducting points from the opposing player"};
    int select1, select2, use_abi_p1=0, use_abi_p2=0;
    char confirm1, confirm2;

    printf("Do you want to know how to play this game?\n(Please answer y/n)\n");
    scanf("%c", &how_to);
    how_to_play(how_to);

    printf("Please enter your name.\n(character can not longer than 10 characer.)\n");
    printf("Player1 : ");
    scanf(" %[^\n]", name1);
    printf("Player2 : ");
    scanf(" %[^\n]", name2);

    printf("It's time to random ability!\n");
    player[0].abil = ability[random_num() % 2];
    player[0].point_abi = (random_num() % 4) + 1;
    player[1].abil = ability[(random_num() + 1) % 2];
    player[1].point_abi = (random_num() % 4) + 1;
    printf("From now on, no other player should see your abilities. Ready or not?\n");
    printf("Please type something to confirm.\n");
    scanf(" %[^\n]", remem);
    system(CLEAR);
    printf("%s your ability is %s (%d)\n", player[0].name, player[0].abil, player[0].point_abi);
    printf("If you've memorized the abilities, please type y\n");
    scanf(" %c", &remem1);
    system(CLEAR);
    printf("%s your ability is %s (%d)\n", player[1].name, player[1].abil, player[1].point_abi);
    printf("If you've memorized the abilities, please type y\n");
    scanf(" %c", &remem2);
    system(CLEAR);
    
    printf("Let's start!!!\n");
    player[0].winscore = 0;
    player[1].winscore = 0;

    for (int i=0; i<3; i++)
    {
        printf("Round %d\n", i+1);
        player[0].totalnumber = 0;
        player[1].totalnumber = 0;
        char set_of_num[41] = {"| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |"};

        for (int i=0; i<10; i++)
            number[i] = random_num();

        for (int i=0; i<3; i++)
        {
            // printf("%s (win %d) score: %d\n", player[0].name, player[0].winscore, player[0].totalnumber);
            printf("%s (win %d) score: %d\n", name1, player[0].winscore, player[0].totalnumber);
            printf("%s (win %d) score: %d\n", name2, player[1].winscore, player[1].totalnumber);
            printf("*****************\n");
            printf("%s", set_of_num);
            printf("\n%s please enter your number you choose.\n", player[0].name);
            scanf("%d", &select1);
            int num1 = check_choose(select1, number, round);
            number[round] = num1;
            round++;
            player[0].totalnumber += number[select1];
            mark_choose(num1, set_of_num);
            system(CLEAR);

            printf("%s (win %d) score: %d\n", name1, player[0].winscore, player[0].totalnumber);
            printf("%s (win %d) score: %d\n", name2, player[1].winscore, player[1].totalnumber);
            printf("*****************\n");
            printf("%s", set_of_num);
            printf("\n%s please enter your number you choose.\n", player[1].name);
            scanf("%d", &select2);
            int num2 = check_choose(select2, number, round);
            number[round] = num2;
            round++;
            player[1].totalnumber += number[select2];
            mark_choose(num2, set_of_num);
            system(CLEAR);
        }

        printf("%s (win %d) score: %d\n", name1, player[0].winscore, player[0].totalnumber);
        printf("%s (win %d) score: %d\n", name2, player[1].winscore, player[1].totalnumber);

        printf("*****************\n");

        if (use_abi_p1 > 0)
            printf("%s, You already used ability.\n", player[0].name);
        else if (use_abi_p1 == 0)
        {
            printf("%s do you want to use your ability?\n", player[0].name);
            printf("(if you want please type y)\n");
            scanf(" %c", &confirm1);
            if (tolower(confirm1) == 'y')
            {
                scores(player, 1);
                use_abi_p1++;
            }
            
        }

        printf("*****************\n");

        if (use_abi_p2 > 0)
            printf("%s, You already used ability.\n", player[1].name);
        else if (use_abi_p2 == 0)
        {
            printf("%s do you want to use your ability?\n", player[1].name); 
            printf("(if you want please type y)\n");
            scanf(" %c", &confirm2);
            if (tolower(confirm2) == 'y')
            {
                scores(player, 2);
                use_abi_p2++;
            }
            
        }

        printf("*****************\n");

        round = 0;

        winner(player);
        system(CLEAR);
        if (player[0].winscore == 2 || player[1].winscore == 2)
            break;
    }

    winner(player);
    printf("END GAME!!!");

    return 0;
}

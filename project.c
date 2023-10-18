#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void how_to_play(char answer);
int random_num();
void delay(int number_of_seconds);
void mark_choose(int number, char set[]);
int check_choose(int num, int number[], int round);
int winner(int winscore1, int winscore2, int totalnumber1, int totalnumber2);

void how_to_play(char answer)
{
    if (tolower(answer) == 'y')
    {
        printf("-------\n");
        printf("How to play this game!\n");
        printf("There are 9 slots, numbers in the range of 0-10, and you can choose only 3 slots. You cannot see the numbers inside the selected slots. ");
        printf("The player with the highest total sum will win that round and must win 2 out of 3 rounds to conclude the game.\n");
        printf("And, of course, we have a special rule. At the beginning of the game, there will be a random ability assigned to each player to help increase your number or decrease the opponent's numbers.");
        printf("\n-------\n");
    }
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
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
            else if (num < 0 || num > 9)
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

int winner(int winscore1, int winscore2, int totalnumber1, int totalnumber2)
{
    if (totalnumber1 > totalnumber2)
    {
        winscore1++;
        return 1;
    }
    else if (totalnumber2 > totalnumber1)
    {
        winscore2++;
        return 2;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char how_to, name1[10], name2[10], ans, ok[100];
    int num[6], number[10];
    int round = 0;
    char *ability[3] = {"Increase your score", "Deducting points from the opposing player", "Increase your win score but random player"};
    int select1, select2, use_abi_p1 = 0, use_abi_p2 = 0;
    char confirm1, confirm2;
    int totalnumber1 = 0, totalnumber2 = 0;
    int winscore1 = 0;
    int winscore2 = 0;

    printf("Do you want to know how to play this game? (Please answer y/n)\n");
    scanf(" %c", &how_to);
    how_to_play(how_to);

    printf("Please enter your names (character names cannot be longer than 10 characters).\n");
    printf("Player 1: ");
    scanf(" %[^\n]", name1);
    printf("Player 2: ");
    scanf(" %[^\n]", name2);

    printf("It's time to random abilities!\n");
    int ability1 = random_num() % 3;
    int point_abi1 = (random_num() % 4) + 1;
    int ability2 = (random_num() + 1) % 3;
    int point_abi2 = (random_num() % 4) + 1;

    printf("From now on, no other player should see your abilities. Ready or not?\n");
    printf("Please type something to confirm.\n");
    scanf(" %[^\n]", ok);
    system(CLEAR);

    if (strcmp(ability[ability1], "Increase your win score but random player") == 0)
        printf("%s, your ability is %s\n", name1, ability[ability1]);
    else printf("%s, your ability is %s (%d)\n", name1, ability[ability1], point_abi1);
    printf("If you've memorized the abilities, please type y\n");
    scanf(" %c", &confirm1);
    system(CLEAR);

    if (strcmp(ability[ability2], "Increase your win score but random player") == 0)
        printf("%s, your ability is %s\n", name1, ability[ability2]);
    else printf("%s, your ability is %s (%d)\n", name2, ability[ability2], point_abi2);
    printf("If you've memorized the abilities, please type y\n");
    scanf(" %c", &confirm2);
    system(CLEAR);
    
    printf("Let's start!!!\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Round %d\n", i + 1);
        totalnumber1 = 0;
        totalnumber2 = 0;
        char set_of_num[41] = "| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |";
        for (int k = 0; k < 10; k++)
        {
            number[k] = random_num();
        }

        for (int j = 0; j < 3; j++)
        {
            printf("%s (win %d) score: %d\n", name1, winscore1, totalnumber1);
            printf("%s (win %d) score: %d\n", name2, winscore2, totalnumber2);
            printf("*****************\n");
            for (int l=0; l<41; l++)
                printf("%c", set_of_num[l]);
            printf("\n");
            printf("%s, please enter the number you choose.\n", name1);
            scanf("%d", &select1);
            int num1 = check_choose(select1, num, round);
            num[round] = num1;
            round++;
            totalnumber1 += number[num1];
            mark_choose(num1, set_of_num);
            system(CLEAR);

            printf("%s (win %d) score: %d\n", name1, winscore1, totalnumber1);
            printf("%s (win %d) score: %d\n", name2, winscore2, totalnumber2);
            printf("*****************\n");
            for (int l=0; l<41; l++)
                printf("%c", set_of_num[l]);
            printf("\n");
            printf("%s, please enter the number you choose.\n", name2);
            scanf("%d", &select2);
            int num2 = check_choose(select2, num, round);
            num[round] = num2;
            round++;
            totalnumber2 += number[num2];
            mark_choose(num2, set_of_num);
            system(CLEAR);
        }

        printf("%s (win %d) score: %d\n", name1, winscore1, totalnumber1);
        printf("%s (win %d) score: %d\n", name2, winscore2, totalnumber2);
        printf("*****************\n");

        if (use_abi_p1 > 0)
            printf("%s, you've already used your ability.\n", name1);
        else if (use_abi_p1 == 0)
        {
            printf("%s, do you want to use your ability?\n", name1);
            printf("(if you want, please type y)\n");
            scanf(" %c", &confirm1);
            if (tolower(confirm1) == 'y')
            {
                if (strcmp(ability[ability1], "Increase your score") == 0)
                    totalnumber1 += point_abi1;
                else if (strcmp(ability[ability1], "Deducting points from the opposing player") == 0)
                    totalnumber2 -= point_abi1;
                else
                {
                    printf("Time to roll!!!\n3\n");
                    int who_get = random_num() % 2;
                    delay(1);
                    printf("2\n");
                    delay(1);
                    printf("1\n");
                    delay(1);
                    if (who_get == 0)
                    {
                        printf("Congratulations to %s! Your win score +1.\n", name1);
                        winscore1++;
                    }
                    else if (who_get == 1)
                    {
                        printf("Congratulations to %s! Your win score +1.\n", name2);
                        winscore2++;
                    }
                    
                }
                use_abi_p1++;
            }
        }

        system(CLEAR);

        printf("%s (win %d) score: %d\n", name1, winscore1, totalnumber1);
        printf("%s (win %d) score: %d\n", name2, winscore2, totalnumber2);
        printf("*****************\n");

        if (use_abi_p2 > 0)
            printf("%s, you've already used your ability.\n", name2);
        else if (use_abi_p2 == 0)
        {
            printf("%s, do you want to use your ability?\n", name2);
            printf("(if you want, please type y)\n");
            scanf(" %c", &confirm2);
            if (tolower(confirm2) == 'y')
            {
                if (strcmp(ability[ability2], "Increase your score") == 0)
                    totalnumber2 += point_abi2;
                else if (strcmp(ability[ability2], "Deducting points from the opposing player") == 0)
                    totalnumber1 -= point_abi2;
                else
                {
                    printf("Time to roll!!!\n3\n");
                    int who_get = random_num() % 2;
                    delay(1);
                    printf("2\n");
                    delay(1);
                    printf("1\n");
                    delay(1);
                    if (who_get == 0)
                    {
                        printf("Congratulations to %s! Your win score +1.\n", name1);
                        winscore1++;
                    }
                    else if (who_get == 1)
                    {
                        printf("Congratulations to %s! Your win score +1.\n", name2);
                        winscore2++;
                    }
                    
                }
                use_abi_p2++;
            }
        }

        printf("*****************\n");
        round = 0;

        int round_winner = winner(winscore1, winscore2, totalnumber1, totalnumber2);

        if (round_winner != 0)
        {
            if (round_winner == 1)
            {
                winscore1++;
                printf("%s wins the round!\n", name1);
            }
            else
            {
                winscore2++;
                printf("%s wins the round!\n", name2);
            }
        }
        else
        {
            printf("It's a draw in this round!\n");
        }

        printf("Do you want to go to the next round? (Please type y to confirm)\n");
        scanf(" %c", &ans);
        if (ans == 'y')
            system(CLEAR);
        if (winscore1 == 2 || winscore2 == 2)
            break;
    }

    int game_winner = winner(winscore1, winscore2, totalnumber1, totalnumber2);
    if (game_winner != 0)
    {
        if (game_winner == 1)
            printf("%s wins the game!\n", name1);
        else
            printf("%s wins the game!\n", name2);
    }
    else
    {
        printf("The game ends in a draw!\n");
    }
    printf("END GAME!!!\n");

    return 0;
}

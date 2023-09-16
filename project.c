#include<stdio.h>
#include<ctype.h>
#include<string.h>

void how_to_play(char answer);

void how_to_play(char answer)
{
    if (tolower(answer) == 'y')
    {
        printf("How to play this game!\n");
        printf("");
    }
}

int main()
{
    char how_to;

    printf("Do you want to know how to play this game?\n(Please answer yes/no)\n");
    scanf("%c", &how_to);

    how_to_play(how_to);
}

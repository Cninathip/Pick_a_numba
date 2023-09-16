#include<stdio.h>
#include<ctype.h>
#include<string.h>

void how_to_play(char answer[]);

void how_to_play(char answer[])
{
    if (strcmp(tolower(answer), "yes"))
    {
        printf("How to play this game!\n");
        printf("");
    }
}

int main()
{
    char how_to[5];

    scanf("Do you want to know how to play this game?\n(Please answer yes/no)\n%s", how_to);

    how_to_play(how_to);
}

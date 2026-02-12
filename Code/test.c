#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int C_randomNum(int max)
{
    int num;
    num = abs(rand()) % max + 1;

    return num;
}

int main(void)
{
    srand(time(0));
    int r;
    for(int i = 0; i < 10; i ++)
    {
        r = C_randomNum(3);
        printf("%d\n", r);
    }
    return 0;
}
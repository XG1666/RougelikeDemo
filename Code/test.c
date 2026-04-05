#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int C_randomNum(int max)
{
    int num;
    num = abs(rand()) % max + 1;

    return num;
}
enum a
{
    q,w,e,r
};

int main(void)
{
    srand(time(0));
    int c;
    c = C_randomNum(3);
    printf("%d\n", c);
    enum a b = (enum a)c;
    printf("%d\n", b);

    switch (b)
    {
    case w:
        printf("w");
        break;
    case e:
        printf("e");
        break;
    case r:
        printf("r");
        break;
    default:
        break;
    }
    return 0;
}
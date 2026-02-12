#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../Character.h"
#include"../Menu.h"

#define mazeEdge 5
extern char key;
extern M_Launguage l;

C_Character hero;
C_Character *ptr_hero = &hero;
C_Position hero_p;
C_Position *ptr_hero_p = &hero_p;

void H_setHero_EN(void)
{
    system("cls");
    printf("Please name your hero: ");
    scanf("%s", hero.name_EN);
    hero.gender = male;
    hero.HP = 100;
    hero.max_HP = 100;
    hero.strength = 5;
    hero.wisdom = 10;
    hero.defence = 8;

    hero_p.x = 0;
    hero_p.y = 0;
    hero_p.direction = d;
}
void H_setHero_CN(void)
{
    system("cls");
    printf("请给你的角色命名：");
    scanf("%s", hero.name_CN);
    hero.gender = male;
    hero.HP = 100;
    hero.max_HP = 100;
    hero.strength = 5;
    hero.wisdom = 10;
    hero.defence = 8;

    hero_p.x = 0;
    hero_p.y = 0;
    hero_p.direction = d;
}
void H_setHero(void)
{
    if(l == EN)
    {
        H_setHero_EN();
    }
    else if (l == CN)
    {
        H_setHero_CN();
    }
}

C_Character *H_getHeroInfo(void)
{
    return ptr_hero;
}

C_Position *H_getHeroPos(void)
{
    return ptr_hero_p;
}

//Check the position
int H_isTop(C_Position *p)
{
    int istop = 0;
    if((p -> x) == 0)
    {
        istop = 1;
    }
    return istop;
}

int H_isBottom(C_Position *p)
{
    int isbottom = 0;
    if((p -> x) == mazeEdge)
    {
        isbottom = 1;
    }
    return isbottom;
}

int H_isLeftEdge(C_Position *p)
{
    int isleftedge = 0;
    if((p -> y) == 0)
    {
        isleftedge = 1;
    }
    return isleftedge;
}

int H_isRightEdge(C_Position *p)
{
    int isrightedge = 0;
    if((p -> y) == mazeEdge)
    {
        isrightedge = 1;
    }
    return isrightedge;
}



/*//Moving
void H_Moving(C_Position *p, char key)
{
    switch (key)
    {
        case 'w':
        {
            p->direction = w;
            if(H_isTop(p))
            {
                printf("It's the wall!\n");
            }
            else
            {
                (p -> x) --;
            }
            break;
        }
        case 'd':
        {
            p->direction = d;
            if(H_isRightEdge(p))
            {
                printf("It's the wall!\n");
            }
            else
            {
                (p -> y) ++;
            }
            break;
        }
        case 's':
        {
            p->direction = s;
            if(H_isBottom(p))
            {
                printf("It's the wall!\n");
            }
            else
            {
                (p -> x) ++;
            }
            break;
        }
        case 'a':
        {
            p->direction = a;
            if(H_isLeftEdge(p))
            {
                printf("It's the wall!\n");
            }
            else
            {
                (p -> y) --;
            }
            break;
        }
        default:
        {
            //printf("Illegal input!\n");
            break;
        }
    }
}*/

int H_Attack(void)
{
    int attack;
    attack = C_Attack(ptr_hero);
    return attack;
}

void H_Hurted(int hurt)
{
    C_Hurted(ptr_hero, hurt);
    if(hero.HP == 0)
    {
        hero.HP = 0;
        key = 'q';
    }
}

void H_addHP(int add)
{
    C_addHP(ptr_hero, add);
}

void H_addDefence(int add)
{
    C_addDefence(ptr_hero, add);
}

void H_addStrength(int add)
{
    C_addStrength(ptr_hero, add);
}
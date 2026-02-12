#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#include"../Character.h"
#include"../Menu.h"

C_Character enemy[3];
C_Character boss;
C_Character *ptr_boss = &boss;
C_Character *ptr_enemy0 = &enemy[0];
C_Character *ptr_enemy1 = &enemy[1];
C_Character *ptr_enemy2 = &enemy[2];

char cle;
extern M_Launguage l;

int C_randomNum(int max)
{
    int num;
    num = abs(rand()) % max + 1;

    return num;
}

void C_initEnemy(void)
{
    strcpy(boss.name_EN, "Evil");
    strcpy(boss.name_CN, "恶灵");
    boss.gender = NA;
    boss.HP = 200;
    boss.max_HP = 200;
    boss.strength = 20;
    boss.defence = 30;
    boss.wisdom = 30;

    strcpy(enemy[0].name_EN, "Mummy");
    strcpy(enemy[0].name_CN, "木乃伊");
    enemy[0].gender = NA;
    enemy[0].HP = (30 + C_randomNum(10));
    enemy[0].max_HP = enemy[0].HP;
    enemy[0].strength = 2;
    enemy[0].defence = 2;
    enemy[0].wisdom = 0;

    strcpy(enemy[1].name_EN, "Slime");
    strcpy(enemy[1].name_CN, "史莱姆");
    enemy[1].gender = NA;
    enemy[1].HP = (20 + C_randomNum(5));
    enemy[1].max_HP = enemy[1].HP;
    enemy[1].strength = 2;
    enemy[1].defence = 5;
    enemy[1].wisdom = 0;

    strcpy(enemy[2].name_EN, "\'Knight\'");
    strcpy(enemy[2].name_CN, "\'骑士\'");
    enemy[2].gender = NA;
    enemy[2].HP = (60 + C_randomNum(10));
    enemy[2].max_HP = enemy[2].HP;
    enemy[2].strength = 12;
    enemy[2].defence = 10;
    enemy[2].wisdom = 0;
}

C_Character *C_getBossInfo(void)
{
    return ptr_boss;
}

C_Character *C_getEnemyInfo(void)
{
    int n = C_randomNum(5);
    C_Character *p;
    switch(n)
    {
        case 1:
        case 4:
        {
            p = ptr_enemy0;
            break;
        }
        case 2:
        case 5:
        {
            p = ptr_enemy1;
            break;
        }
        case 3:
        {
            p = ptr_enemy2;
            break;
        }
        default:
        {
            p = NULL;
            break;
        }
    }
    return p;
}

int C_Attack(C_Character *p)
{
    int attack;
    attack = C_randomNum(20) + (p->strength);
    return attack;
}

void C_Hurted_EN(C_Character *p, int hurt)
{
    (p->HP) -= abs(hurt - (p->defence));
    printf("%s takes %d point of damage!\n", (p->name_EN), abs(hurt - (p->defence)));

    if((p->HP) <= 0)
    {
        p->HP = 0;
        printf("%s is killed!\n", (p->name_EN));
    }
    scanf("%c", &cle);
}
void C_Hurted_CN(C_Character *p, int hurt)
{
    (p->HP) -= abs(hurt - (p->defence));
    printf("%s 受到了 %d 点伤害！\n", (p->name_CN), abs(hurt - (p->defence)));

    if((p->HP) <= 0)
    {
        p->HP = 0;
        printf("%s 被杀死了！\n", (p->name_CN));
    }
    scanf("%c", &cle);
}
void C_Hurted(C_Character *p, int hurt)
{
    if(l == EN)
    {
        C_Hurted_EN(p, hurt);
    }
    else if (l == CN)
    {
        C_Hurted_CN(p, hurt);
    }
}

void C_addHP_EN(C_Character *p, int add)
{
    if((p->HP) + add >= (p->max_HP))
    {
        (p->HP) = (p->max_HP);
        printf("%s recovers\n", (p->name_EN));
    }
    else
    {
        (p->HP) += add;
        printf("%s gets %d points of HP\n", (p->name_EN), add);
    }
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addHP_CN(C_Character *p, int add)
{
    if((p->HP) + add >= (p->max_HP))
    {
        (p->HP) = (p->max_HP);
        printf("%s 痊愈了！\n", (p->name_CN));
    }
    else
    {
        (p->HP) += add;
        printf("%s 恢复了 %d 点血量！\n", (p->name_CN), add);
    }
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addHP(C_Character *p, int add)
{
    if(l == EN)
    {
        C_addHP_EN(p, add);
    }
    else if (l == CN)
    {
        C_addHP_CN(p, add);
    }
}

void C_addDefence_EN(C_Character *p, int add)
{
    (p->defence) += add;
    printf("%s gets %d points of defence\n", (p->name_EN), add);
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addDefence_CN(C_Character *p, int add)
{
    (p->defence) += add;
    printf("%s 获得 %d 点防御\n", (p->name_EN), add);
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addDefence(C_Character *p, int add)
{
    if(l == EN)
    {
        C_addDefence_EN(p, add);
    }
    else if (l == CN)
    {
        C_addDefence_CN(p, add);
    }
}

void C_addStrength_EN(C_Character *p, int add)
{
    (p->strength) += add;
    printf("%s gets %d points of strength\n", (p->name_EN), add);
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addStrength_CN(C_Character *p, int add)
{
    (p->strength) += add;
    printf("%s 获得 %d 点力量\n", (p->name_CN), add);
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void C_addStrength(C_Character *p, int add)
{
    if(l == EN)
    {
        C_addStrength_EN(p, add);
    }
    else if (l == CN)
    {
        C_addStrength_CN(p, add);
    }
}

int C_enemyAction(C_Character *e)
{
    int e_attack = 0;

    e_attack = C_Attack(e);

    return e_attack;
}
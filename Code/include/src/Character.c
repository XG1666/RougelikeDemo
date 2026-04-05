#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#include"../Character.h"
#include"../Hero.h"
#include"../Menu.h"

C_Character enemy[3];
C_Character boss;
C_Character *ptr_boss = &boss;
C_Character *ptr_enemy0 = &enemy[0];
C_Character *ptr_enemy1 = &enemy[1];
C_Character *ptr_enemy2 = &enemy[2];

char cle;
extern M_Launguage l;
extern int *VTRe;

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

void C_getEquipmentDscp_EN(C_EquipmentType eq)
{
    switch(eq)
    {
        case EM:
        {
            printf("Empty\n");
            break;
        }
        case FlyingCannon:
        {
            printf("FlyingCannon.\nRegardless the defence, when calculate damage each turn, create 2 points of damages to the enemy.\n");
            break;
        }
        case VampireTooth:
        {
            printf("VampireTooth.\nGet certain points of health, which equals to half of the damage you cause.\n");
            break;
        }
        default:
            break;
    }
}
void C_getEquipmentDscp_CN(C_EquipmentType eq)
{
    switch(eq)
    {
        case EM:
        {
            printf("空\n");
            break;
        }
        case FlyingCannon:
        {
            printf("浮游炮。\n无视防御, 每回合我方伤害结算时对敌人造成2点伤害。\n");
            break;
        }
        case VampireTooth:
        {
            printf("吸血鬼之牙。\n回复你对敌人造成的伤害的一半的生命值\n");
            break;
        }
        default:
            break;
    }
}
void C_getEquipmentDscp(C_EquipmentType eq)
{
    if(l == EN)
    {
        C_getEquipmentDscp_EN(eq);
    }
    else if (l == CN)
    {
        C_getEquipmentDscp_CN(eq);
    }
}

void C_EquipmentBB(C_Character *h, C_Character *e)
{
    for(int i = 0; i < 3; i ++)
    {
        switch(h->equipment[i])
        {
            case EM:
            {
                break;
            }
            default:
                break;
        }
    }
}
void C_EquipmentCD(C_Character *h, C_Character *e)
{
    if(e->HP)
    {
        for(int i = 0; i < 3; i ++)
        {
            switch(h->equipment[i])
            {
                case EM:
                {
                    break;
                }
                case FlyingCannon:
                {
                    e->hurt = 2;
                    C_Hurted(e);
                    break;
                }
                case VampireTooth:
                {
                    H_addHP(*VTRe);
                    break;
                }
                default:
                    break;
            }
        }
    }
}
void C_EquipmentAB(C_Character *h, C_Character *e)
{
    for(int i = 0; i < 3; i ++)
    {
        switch(h->equipment[i])
        {
            case EM:
            {
                break;
            }
            default:
                break;
        }
    }
}

int C_Attack(C_Character *p1, C_Character *p2)
{
    int attack;
    attack = C_randomNum(20) + (p1->strength);

    p2->hurt = attack;
    if(p2->hurt < 0)
    {
        p2->hurt = 0;
    }
    return attack;
}

void C_Hurted_EN(C_Character *p)
{
    (p->HP) -= p->hurt;
    printf("%s takes %d point of damage!\n", (p->name_EN), p->hurt);

    if((p->HP) <= 0)
    {
        p->HP = 0;
        printf("%s is killed!\n", (p->name_EN));
    }
    
    while(getchar() != '\n'){}
}
void C_Hurted_CN(C_Character *p)
{
    (p->HP) -= p->hurt;
    printf("%s 受到了 %d 点伤害！\n", (p->name_CN), p->hurt);

    if((p->HP) <= 0)
    {
        p->HP = 0;
        printf("%s 被杀死了！\n", (p->name_CN));
    }
    
    while(getchar() != '\n'){}
}
void C_Hurted(C_Character *p)
{
    if(l == EN)
    {
        C_Hurted_EN(p);
    }
    else if (l == CN)
    {
        C_Hurted_CN(p);
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

int C_enemyAction(C_Character *e, C_Character *h)
{
    int e_attack = 0;

    e_attack = C_Attack(e, h);

    return e_attack;
}
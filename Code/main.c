#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#include"include/Menu.h"
#include"include/Character.h"
#include"include/Hero.h"

char key;
extern char cle;
int stepcnt = 0;
M_Launguage l;

int main(void)
{
    SetConsoleOutputCP(65001);
    srand(time(0));
    M_selectL();
    M_showStartMenu();
    scanf("%c", &key);
    scanf("%c", &key);
    if(key == 's')
    {
        /*存档功能待开发
        M_showLoadMenu();
        scanf("%c, &key");
        if(key == 1)
        {

        }
        else if(key == 2)
        {

        }
        else
        {
            printf("Game Quits!");
        }
        */

        H_setHero();
        M_showWelcomeHero(H_getHeroInfo());
        
        while(H_getHeroInfo() -> HP)
        {
            C_initEnemy();
            M_showWay(H_getHeroPos());
            scanf("%c", &key);
            if(key == 'q')
            {
                printf("Game Quits!");
                break;
            }
            else
            {
                if (stepcnt <= 20)
                {
                    //H_Moving(H_getHeroPos(), key);
                    C_Position *h = H_getHeroPos();
                    switch (key)
                    {
                        case 'w':
                        {
                            h->direction = w;
                            if(H_isTop(h))
                            {
                                printf("It's the wall!\n");
                                continue;
                            }
                            else
                            {
                                (h -> x) --;
                            }
                            break;
                        }
                        case 'd':
                        {
                            h->direction = d;
                            if(H_isRightEdge(h))
                            {
                                printf("It's the wall!\n");
                                continue;
                            }
                            else
                            {
                                (h -> y) ++;
                            }
                            break;
                        }
                        case 's':
                        {
                            h->direction = s;
                            if(H_isBottom(h))
                            {
                                printf("It's the wall!\n");
                                continue;
                            }
                            else
                            {
                                (h -> x) ++;
                            }
                            break;
                        }
                        case 'a':
                        {
                            h->direction = a;
                            if(H_isLeftEdge(h))
                            {
                                printf("It's the wall!\n");
                                continue;
                            }
                            else
                            {
                                (h -> y) --;
                            }
                            break;
                        }
                        default:
                        {
                            printf("Illegal input!\n");
                            continue;
                        }
                    }

                    stepcnt ++;

                    switch (C_randomNum(3))
                    {
                    case 1:
                    case 3:
                        {
                            C_Character *e = C_getEnemyInfo();
                            M_showBattleMenu(H_getHeroInfo(), e);
                            if(e->HP == 0)
                            {
                                M_showAwardMenu();
                            }
                            break;
                        }
                    case 2:
                        M_showAddMenu();
                    default:
                        break;
                    }
                }
                else
                {
                    M_showPreperation();
                    M_showBossBattleMenu(H_getHeroInfo(), C_getBossInfo());
                    M_showEnd(H_getHeroInfo());
                    break;
                }
            }
                

        }
    }
    return 0;
}
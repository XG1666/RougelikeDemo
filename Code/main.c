#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#include"include/Menu.h"//About context and menu 关于文本及界面
#include"include/Character.h"//About basic character 关于基本角色（角色模板及敌人）
#include"include/Hero.h"//About hero 关于主角

char key;
extern char cle;
int stepcnt = 0;
M_Launguage l;

int main(void)
{
    SetConsoleOutputCP(65001);//Simplified Chinese setting 设置简体中文
    srand(time(0));//Random seed setting 设置随机数种子

    M_selectL();
    M_showStartMenu();
    scanf("%c", &key);
    scanf("%c", &key);//Welcome 入场

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

        H_setHero();//Initialize the hero 初始化角色
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
                if (stepcnt <= 15)
                {
                    //Hero moves, entering rooms 角色移动，进入房间
                    C_Position *h = H_getHeroPos();
                    switch (key)
                    {
                        case 'i':
                        {
                            M_showHeroInfo(H_getHeroInfo());
                            continue;
                        }
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
                    //

                    //Enter room 进入房间
                    //Select room type with random number 随机房间类型
                    //
                    //In the room 房间事件发生
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
                    //

                }
                
                //After 15 steps, enter boss' room 15步进入boss房
                else
                {
                    M_showPreperation();
                    M_showBossBattleMenu(H_getHeroInfo(), C_getBossInfo());
                    M_showEnd(H_getHeroInfo());
                    break;
                }
                //
            }
                

        }
    }
    return 0;
}
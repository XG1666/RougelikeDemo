#include<stdio.h>
#include<stdlib.h>

#include"../Character.h"
#include"../Hero.h"
#include"../Menu.h"

#define mazeEdge 5

extern int glacier;
extern char key;
extern char cle;
extern M_Launguage l;

void M_selectL(void)
{
    system("cls");
    int L;
    printf("**************************\n");
    printf("       1.English\n");
    printf("       2.简体中文\n");
    printf("**************************\n");
    scanf("%d", &L);

    switch (L)
    {
        case 1:
        {
            l = EN;
            break;
        }
        case 2:
        {
            l = CN;
            break;
        }
    }
}

void M_showStartMenu_EN(void)
{
    system("cls");
    printf("**************************\n");
    printf("     Welcome to Maze\n");
    printf("   press \'s\' to start!\n");
    printf(" press other keys to quit\n");
    printf("**************************\n");
}
void M_showStartMenu_CN(void)
{
    system("cls");
    printf("**************************\n");
    printf("     欢迎来到恶灵迷宫\n");
    printf("    按下 \'s\' 以继续！\n");
    printf("   按下其他按键退出游戏。\n");
    printf("**************************\n");
}
void M_showStartMenu(void)
{
    if(l == EN)
    {
        M_showStartMenu_EN();
    }
    else if (l == CN)
    {
        M_showStartMenu_CN();
    }
    
}

void M_showLoadMenu(void)
{
    system("cls");
    printf("**************************\n");
    printf("       Please select:\n");
    printf("   1.Create a new hero\n");
    printf("      2.Load hero\n");
    printf(" press other keys to quit\n");
    printf("**************************\n");
}

void M_showWelcomeHero_EN(C_Character *p)
{
    system("cls");
    printf("**************************\n");
    printf("       Hello, %s.\n", p -> name_EN);
    printf("Welcome to the Great Maze!\n");
    printf("     Your goal is to\n");
    printf("      kill the Evil\n");
    printf("    and its followers\n");
    printf("**************************\n");
    
    scanf("%c", &cle);
    scanf("%c", &cle);

    system("cls");
    printf("**************************\n");
    printf("   It's time to start!\n");
    printf("**************************\n");
    scanf("%c", &cle);
}
void M_showWelcomeHero_CN(C_Character *p)
{
    system("cls");
    printf("**************************\n");
    printf("       你好，%s。\n", p -> name_CN);
    printf("     欢迎来到迷宫！\n");
    printf("     你此行的目标是\n");
    printf("    杀掉恶灵及其拥趸\n");
    printf("**************************\n");
    
    //scanf("%c", &cle);
    scanf("%c", &cle);
    while(getchar() != '\n'){}

    system("cls");
    printf("**************************\n");
    printf("       是时候启程了！\n");
    printf("**************************\n");
    scanf("%c", &cle);
}
void M_showWelcomeHero(C_Character *p)
{
    if(l == EN)
    {
        M_showWelcomeHero_EN(p);
    }
    else if (l == CN)
    {
        M_showWelcomeHero_CN(p);
    }
}

void M_showEquipmentInfo_EN(C_Character *h)
{
    for(int i = 0; i < 3; i ++)
    {
        printf("Equipment %d: ", i+1);
        C_getEquipmentDscp(h -> equipment[i]);
        printf("\n");
    }
}
void M_showEquipmentInfo_CN(C_Character *h)
{
    for(int i = 0; i < 3; i ++)
    {
        printf("装备 %d: ", i+1);
        C_getEquipmentDscp(h -> equipment[i]);
        printf("\n");
    }
}

void M_showHeroInfo_EN(C_Character *h)
{
    system("cls");

    printf("**************************\n");
    printf("name:%s\n", h->name_EN);
    printf("HP:%d\n", h->HP);
    printf("Strength:%d\n", h->strength);
    printf("Defence:%d\n", h->defence);
    printf("\n");
    M_showEquipmentInfo_EN(h);
    printf("**************************\n");
}
void M_showHeroInfo_CN(C_Character *h)
{
    system("cls");

    printf("**************************\n");
    printf("姓名：%s\n", h->name_CN);
    printf("血量：%d\n", h->HP);
    printf("力量：%d\n", h->strength);
    printf("防御：%d\n", h->defence);
    printf("\n");
    M_showEquipmentInfo_CN(h);
    printf("**************************\n");
}
void M_showHeroInfo(C_Character *h)
{
    if(l == EN)
    {
        M_showHeroInfo_EN(h);
    }
    else if (l == CN)
    {
        M_showHeroInfo_CN(h);
    }

    scanf("%c", &cle);
    while(getchar() != '\n'){}
}

void M_showEntry(void)//二周目入口
{
    printf("***********    ***********\n");
    printf("*       Go Forward       *\n");
    printf("*          (W)           *\n");
    printf("*                 Go Right\n");
    printf("*                    (D)  \n");
    printf("*       Go Backward      *\n");
    printf("*           (S)          *\n");
    printf("***********    ***********\n");
}

void M_showWay_EN(C_Position *p)
{
    system("cls");
    //默认俯视角看地图
    if((p->x) == 0)//(0,y)
    {
        if((p->y) == 0)//(0,0)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("*                 Go Right\n");
            printf("*                    (D)  \n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else if ((p->y) == mazeEdge)//(0,edge)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("Go Left                  *\n");
            printf("  (A)                    *\n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else//(0,y)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("Go Left           Go Right\n");
            printf("  (A)                (D)  \n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
    }
    else if((p->x) == mazeEdge)//(edge,y)
    {
        if ((p->y) == 0)//(edge,0)
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("*                 Go Right\n");
            printf("*                    (D)  \n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
        else if ((p->y) == mazeEdge)//(edge,edge)
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("Go Left                  *\n");
            printf("  (A)                    *\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
        else//(edge,y)
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("Go Left           Go Right\n");
            printf("  (A)                (D)  \n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
    }
    else//(x,y)
    {
        if((p->y) == 0)//(x,0)
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("*                 Go Right\n");
            printf("*                    (D)  \n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else if((p->y) == mazeEdge)//(x,edge)
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("Go Left                  *\n");
            printf("  (A)                    *\n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else
        {
            printf("***********    ***********\n");
            printf("*       Go Forward       *\n");
            printf("*          (W)           *\n");
            printf("Go Left           Go Right\n");
            printf("  (A)               (D)   \n");
            printf("*       Go Backward      *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
    }
}
void M_showWay_CN(C_Position *p)
{
    system("cls");
    //默认俯视角看地图
    if((p->x) == 0)//(0,y)
    {
        if((p->y) == 0)//(0,0)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("*                   向右走 \n");
            printf("*                    (D)  \n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else if ((p->y) == mazeEdge)//(0,edge)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf(" 向左走                   *\n");
            printf("  (A)                    *\n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else//(0,y)
        {
            printf("**************************\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf(" 向左走             向右走 \n");
            printf("  (A)                (D)  \n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
    }
    else if((p->x) == mazeEdge)//(edge,y)
    {
        if ((p->y) == 0)//(edge,0)
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)            *\n");
            printf("*                   向右走\n");
            printf("*                    (D)  \n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
        else if ((p->y) == mazeEdge)//(edge,edge)
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)           *\n");
            printf(" 向左走                   *\n");
            printf("  (A)                    *\n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
        else//(edge,y)
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)           *\n");
            printf(" 向左走              向右走\n");
            printf("  (A)                (D)  \n");
            printf("*                        *\n");
            printf("*                        *\n");
            printf("**************************\n");
        }
    }
    else//(x,y)
    {
        if((p->y) == 0)//(x,0)
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)           *\n");
            printf("*                   向右走 \n");
            printf("*                    (D)  \n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else if((p->y) == mazeEdge)//(x,edge)
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)           *\n");
            printf(" 向左走                   *\n");
            printf("  (A)                    *\n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
        else
        {
            printf("***********    ***********\n");
            printf("*         向上走          *\n");
            printf("*          (W)           *\n");
            printf(" 向左走             向右走 \n");
            printf("  (A)                (D)   \n");
            printf("*          向下走         *\n");
            printf("*           (S)          *\n");
            printf("***********    ***********\n");
        }
    }
}
void M_showWay(C_Position *p)
{
    if(l == EN)
    {
        M_showWay_EN(p);
    }
    else if (l == CN)
    {
        M_showWay_CN(p);
    }
}

void M_showAddHPMenu_EN(void)
{
    system("cls");
    printf("********\n");
    printf(" Add HP\n");
    printf("*****************************\n");
    printf("    1.Take some medicine\n");
    printf("          2.Leave\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addHP(C_randomNum(30));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddHPMenu_CN(void)
{
    system("cls");
    printf("********\n");
    printf("  圣泉\n");
    printf("*****************************\n");
    printf("   1.饮用泉水（回复一定血量）\n");
    printf("        2.转身离去\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addHP(10 + C_randomNum(10));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddHPMenu(void)
{
    if(l == EN)
    {
        M_showAddHPMenu_EN();
    }
    else if (l == CN)
    {
        M_showAddHPMenu_CN();
    }
}

void M_showAddStrengthMenu_EN(void)
{
    system("cls");
    printf("********\n");
    printf("Add Stregth\n");
    printf("*****************************\n");
    printf(" 1.Inject muscle stimulation\n");
    printf("          2.Leave\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addStrength(C_randomNum(10));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddStrengthMenu_CN(void)
{
    system("cls");
    printf("********\n");
    printf(" 实验室\n");
    printf("*****************************\n");
    printf("1.注射肌肉强化剂（增加一定力量值）\n");
    printf("        2.转身离开\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addStrength(5 + C_randomNum(5));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddStrengthMenu(void)
{
    if(l == EN)
    {
        M_showAddStrengthMenu_EN();
    }
    else if (l == CN)
    {
        M_showAddStrengthMenu_CN();
    }
}

void M_showAddDefenceMenu_EN(void)
{
    system("cls");
    printf("********\n");
    printf("Add Defence\n");
    printf("*****************************\n");
    printf("   1.Strengthen the armour\n");
    printf("          2.Leave\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addDefence(C_randomNum(10));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddDefenceMenu_CN(void)
{
    system("cls");
    printf("********\n");
    printf(" 铁匠铺\n");
    printf("*****************************\n");
    printf("  1.锻造盔甲（增加一定防御值）\n");
    printf("         2.转身离开\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        H_addDefence(5 + C_randomNum(5));
        break;
    
    case '2':
        break;
    default:
        break;
    }
}
void M_showAddDefenceMenu(void)
{
    if(l == EN)
    {
        M_showAddDefenceMenu_EN();
    }
    else if (l == CN)
    {
        M_showAddDefenceMenu_CN();
    }
}

void M_showAddMenu(void)
{
    int r = C_randomNum(3);
    scanf("%c", &cle);
    switch (r)
    {
    case 1:
        {
            M_showAddStrengthMenu();
            break;
        }
    case 2:
        {
            M_showAddHPMenu();
            break;
        }
    case 3:
        {
            M_showAddDefenceMenu();
            break;
        }
    default:
        {
            scanf("%c", &cle);
            break;
        }
    }
}

void M_showEquipmentMenu_EN(int eq, C_Character *h)
{
    eq = (C_EquipmentType)eq;

    system("cls");
    printf("*********\n");
    printf("Equipment\n");
    printf("*****************************\n");
    printf("Pick up the equipment or just leave (type \'4\') :\n\n");
    C_getEquipmentDscp(eq);
    printf("\n");
    printf("*****************************\n");
    M_showEquipmentInfo_EN(h);
    printf("*****************************\n");

    scanf(" %c", &key);
    switch(key)
    {
        case '1':
            h->equipment[0] = eq;
            break;
        case '2':
            h->equipment[1] = eq;
            break;
        case '3':
            h->equipment[2] = eq;
            break;
        case '4':
            break;
    }
}
void M_showEquipmentMenu_CN(int eq, C_Character *h)
{
    eq = (C_EquipmentType)eq;

    system("cls");
    printf("*********\n");
    printf("  装备库\n");
    printf("*****************************\n");
    printf("拾起此装备, 或者直接离开 (输入\'4\') :\n\n");
    C_getEquipmentDscp(eq);
    printf("\n");
    printf("*****************************\n");
    M_showEquipmentInfo_CN(h);
    printf("*****************************\n");

    scanf(" %c", &key);
    switch(key)
    {
        case '1':
            h->equipment[0] = eq;
            break;
        case '2':
            h->equipment[1] = eq;
            break;
        case '3':
            h->equipment[2] = eq;
            break;
        case '4':
            break;
    }
}
void M_showEquipmentMenu(int eq, C_Character *h)
{
    if(l == EN)
    {
        M_showEquipmentMenu_EN(eq, h);
    }
    else if (l == CN)
    {
        M_showEquipmentMenu_CN(eq, h);
    }

    while(getchar() != '\n'){}
}

void M_showAwardMenu_EN(void)
{
    system("cls");
    printf("********\n");
    printf(" Award\n");
    printf("*****************************\n");
    printf("    1.Take some medicine\n");
    printf(" 2.Inject muscle stimulation\n");
    printf("   3.Strengthen the armour\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        {
            H_addHP(5 + C_randomNum(10));
            break;
        }
    
    case '2':
        {
            H_addStrength(2 + C_randomNum(5));
            break;
        }

    case '3':
        {
            H_addDefence(3 + C_randomNum(5));
            break;
        }
    
    default:
        break;
    }

    //scanf("%c", &cle);
}
void M_showAwardMenu_CN(void)
{
    system("cls");
    printf("********\n");
    printf(" 战利品\n");
    printf("*****************************\n");
    printf("   1.服用药物（回复一定血量）\n");
    printf("  2.强化肌肉（增加一定力量值）\n");
    printf("  3.加固盔甲（增加一定防御值）\n");
    printf("*****************************\n");
    scanf("%c", &key);

    switch (key)
    {
    case '1':
        {
            H_addHP(5 + C_randomNum(10));
            break;
        }
    
    case '2':
        {
            H_addStrength(2 + C_randomNum(5));
            break;
        }

    case '3':
        {
            H_addDefence(3 + C_randomNum(5));
            break;
        }
    
    default:
        break;
    }

    //scanf("%c", &cle);
}
void M_showAwardMenu(void)
{
    if(l == EN)
    {
        M_showAwardMenu_EN();
    }
    else if (l == CN)
    {
        M_showAwardMenu_CN();
    }
}

void M_showBattleMenu_EN(C_Character *h, C_Character *e)
{
    while((h->HP) && (e->HP))
    {
        //Show the menu
        system("cls");
        printf("********\n");
        printf(" Battle\n");
        printf("*****************************\n");
        printf("%s                %s\n", h->name_EN, e->name_EN);
        printf("HP:%d           HP:%d\n", h->HP, e->HP);
        printf("Strength:%d       Strength:%d\n", h->strength, e->strength);
        printf("Defence:%d        Defence:%d\n", h->defence, e->defence);
        printf("*****************************\n");
        printf("Action: \n");
        printf("1.Attack  2.Defence  3.Leave\n");
        printf("*****************************\n");
        scanf("%c", &key);
        //

        //Confirm action
        if(key == '1')
        {
            //Before battle stage
            C_EquipmentBB(h, e);
            //

            //Calculate damages
            H_Attack(e);//Generate enemy's damage
            C_Hurted(e);//hurt

            C_EquipmentCD(h, e);
            //

            //After battle stage
            if(e->HP != 0)
            {
                C_enemyAction(e, h);
                C_EquipmentAB(h, e);
                H_Hurted();
            }
            else
            {
                break;
            }
            //
        }
        else if(key == '2')
        {
            h->hurt = 0;
            H_Hurted();
            scanf("%c", &cle);
        }
        else if(key == '3')
        {
            if(C_randomNum(20) >= 15)
            {
                printf("Run successfully!\n");
                scanf("%c", &cle);
                //scanf("%c", &cle);
                break;
            }
            else
            {
                printf("Failed to run away!\n");
                C_enemyAction(e, h);
                H_Hurted();
                scanf("%c", &cle);
                //scanf("%c", &cle);
                continue;
            }
        }
        else if(key == 'i')
        {
            M_showHeroInfo(H_getHeroInfo());
            continue;
        }
        
    }
    if(h->HP <= 0)
    {
        printf("Game Over!\n");
    }
    scanf("%c", &cle);
}
void M_showBattleMenu_CN(C_Character *h, C_Character *e)
{
    while((h->HP) && (e->HP))
    {
        //战斗界面
        system("cls");
        printf("********\n");
        printf("  战斗\n");
        printf("*****************************\n");
        printf("%s                %s\n", h->name_CN, e->name_CN);
        printf("血量:%d           血量:%d\n", h->HP, e->HP);
        printf("力量:%d           力量:%d\n", h->strength, e->strength);
        printf("防御:%d           防御:%d\n", h->defence, e->defence);
        printf("*****************************\n");
        printf("行动: \n");
        printf("1.攻击   2.防御   3.逃离\n");
        printf("*****************************\n");
        scanf("%c", &key);
        //

        //确认操作
        if(key == '1')
        {
            //准备阶段
            C_EquipmentBB(h, e);
            //

            //战阶
            H_Attack(e);//Generate enemy's damage
            C_Hurted(e);//hurt

            C_EquipmentCD(h, e);
            //

            //战后结算
            if(e->HP != 0)
            {
                C_enemyAction(e, h);
                C_EquipmentAB(h, e);
                H_Hurted();
            }
            else
            {
                break;
            }
            //
        }
        else if(key == '2')
        {
            h->hurt = 0;
            H_Hurted();
            scanf("%c", &cle);
        }
        else if(key == '3')
        {
            if(C_randomNum(20) >= 15)
            {
                printf("成功逃脱！\n");
                scanf("%c", &cle);
                break;
            }
            else
            {
                printf("逃脱失败！\n");
                C_enemyAction(e, h);
                H_Hurted();
                scanf("%c", &cle);
                continue;
            }
        }
        else if(key == 'i')
        {
            M_showHeroInfo(H_getHeroInfo());
            continue;
        }
        
    }
    if(h->HP <= 0)
    {
        printf("游戏结束！\n");
    }
    scanf("%c", &cle);
}
void M_showBattleMenu(C_Character *h, C_Character *e)
{
    glacier = 0;
    if(l == EN)
    {
        M_showBattleMenu_EN(h, e);
    }
    else if (l == CN)
    {
        M_showBattleMenu_CN(h, e);
    }
}

void M_showBossBattleMenu_EN(C_Character *h, C_Character *e)
{
    while((h->HP) && (e->HP))
    {
        //Show the menu
        system("cls");
        printf("********\n");
        printf(" Battle\n");
        printf("*****************************\n");
        printf("%s                %s\n", h->name_EN, e->name_EN);
        printf("HP:%d             HP:%d\n", h->HP, e->HP);
        printf("Strength:%d       Strength:%d\n", h->strength, e->strength);
        printf("Defence:%d        Defence:%d\n", h->defence, e->defence);
        printf("*****************************\n");
        printf("Action: \n");
        printf("1.Attack  2.Defence\n");
        printf("*****************************\n");
        scanf("%c", &key);
        //

        //Confirm action
        if(key == '1')
        {
            //Before battle stage
            C_EquipmentBB(h, e);
            //

            //Calculate damages
            H_Attack(e);//Generate enemy's damage
            C_Hurted(e);//hurt

            C_EquipmentCD(h, e);
            //

            //After battle stage
            if(e->HP != 0)
            {
                C_enemyAction(e, h);
                C_EquipmentAB(h, e);
                H_Hurted();
            }
            else
            {
                break;
            }
            //
        }
        else if(key == '2')
        {
            h->hurt = 0;
            H_Hurted();
            scanf("%c", &cle);
        }
        else if(key == 'i')
        {
            M_showHeroInfo(H_getHeroInfo());
            continue;
        }
    }
    if(h->HP <= 0)
    {
        printf("Game Over!\n");
    }
    scanf("%c", &cle);
}
void M_showBossBattleMenu_CN(C_Character *h, C_Character *e)
{
    while((h->HP) && (e->HP))
    {
        //战斗界面
        system("cls");
        printf("********\n");
        printf("  战斗\n");
        printf("*****************************\n");
        printf("%s                %s\n", h->name_CN, e->name_CN);
        printf("血量:%d           血量:%d\n", h->HP, e->HP);
        printf("力量:%d           力量:%d\n", h->strength, e->strength);
        printf("防御:%d           防御:%d\n", h->defence, e->defence);
        printf("*****************************\n");
        printf("行动: \n");
        printf("1.攻击   2.防御\n");
        printf("*****************************\n");
        scanf("%c", &key);
        //

        //确认操作
        if(key == '1')
        {
            //准备阶段
            C_EquipmentBB(h, e);
            //

            //战阶
            H_Attack(e);//Generate enemy's damage
            C_Hurted(e);//hurt

            C_EquipmentCD(h, e);
            //

            //战后结算
            if(e->HP != 0)
            {
                C_enemyAction(e, h);
                C_EquipmentAB(h, e);
                H_Hurted();
            }
            else
            {
                break;
            }
            //
        }
        else if(key == '2')
        {
            h->hurt = 0;
            H_Hurted();
            scanf("%c", &cle);
        }
        else if(key == 'i')
        {
            M_showHeroInfo(H_getHeroInfo());
            continue;
        }
    }
    if(h->HP <= 0)
    {
        printf("游戏结束！\n");
    }
    scanf("%c", &cle);
}
void M_showBossBattleMenu(C_Character *h, C_Character *e)
{
    if(l == EN)
    {
        M_showBattleMenu_EN(h, e);
    }
    else if (l == CN)
    {
        M_showBattleMenu_CN(h, e);
    }
}

void M_showPreperation_EN(void)
{
    system("cls");
    printf("***************************************\n");
    printf("  Now, you are in front of the Evil.\n");
    printf("  It's the time to end its threat!\n");
    printf("***************************************\n");
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void M_showPreperation_CN(void)
{
    system("cls");
    printf("***************************************\n");
    printf("        现在，你将直面恶灵\n");
    printf("       是时候终结其威胁了！\n");
    printf("***************************************\n");
    scanf("%c", &cle);
    scanf("%c", &cle);
}
void M_showPreperation(void)
{
    if(l == EN)
    {
        M_showPreperation_EN();
    }
    else if (l == CN)
    {
        M_showPreperation_CN();
    }
}

void M_showEnd_EN(C_Character *h)
{
    system("cls");
    if(h->HP == 0)
    {
        printf("***************************************\n");
        printf("%s is killed by the Evil.\n", h->name_EN);
        printf("His body will become skeleton\n");
        printf("and his name will fade in the history.\n");
        printf("Other adventurers will follow his step\n");
        printf("again, again, and again...\n");
        printf("***************************************\n");
    }
    else
    {
        printf("***************************************\n");
        printf("The Evil is killed by %s.\n", h->name_EN);
        printf("We will never worry about its threat.\n");
        printf("The citizens builds a statue in his honor\n");
        printf("and his name will shine in the history\n");
        printf("forever and ever...\n");
        printf("***************************************\n");
    }
    scanf("%c", &cle);
}
void M_showEnd_CN(C_Character *h)
{
    system("cls");
    if(h->HP == 0)
    {
        printf("***************************************\n");
        printf("%s 被恶灵杀死了\n", h->name_CN);
        printf("他的身躯将会化为白骨\n");
        printf("他的名字将会消散在历史长河中\n");
        printf("后继者将会追随其步伐\n");
        printf("一遍，一遍，又一遍......\n");
        printf("***************************************\n");
    }
    else
    {
        printf("***************************************\n");
        printf("恶灵被 %s 杀死了\n", h->name_CN);
        printf("后代将不再活于其淫威之下\n");
        printf("人们为你筑起纪念碑\n");
        printf("而你的名字将会永远闪耀在历史之中\n");
        printf("永远，永远，直到......\n");
        printf("***************************************\n");
    }
    scanf("%c", &cle);
}
void M_showEnd(C_Character *h)
{
    if(l == EN)
    {
        M_showEnd_EN(h);
    }
    else if (l == CN)
    {
        M_showEnd_CN(h);
    }
}
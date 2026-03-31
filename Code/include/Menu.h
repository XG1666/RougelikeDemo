#ifndef MENU_H
#define MENU_H

#include"Character.h"

typedef enum
{
    CN = 0, EN = 1
} M_Launguage;

typedef enum
{
    battle0 = 0,
    battle1,
    battle2,
    add_HP,
    add_strength,
    add_defence
} M_RoomType;

void M_selectL(void);
void M_showStartMenu(void);
void M_showLoadMenu(void);
void M_showWelcomeHero(C_Character *p);
void M_showHeroInfo(C_Character *h);
void M_showWay(C_Position *p);
void M_showAddMenu(void);
void M_showAwardMenu(void);
void M_showBattleMenu(C_Character *h, C_Character *e);
void M_showBossBattleMenu(C_Character *h, C_Character *e);
void M_showPreperation(void);
void M_showEnd(C_Character *h);

#endif

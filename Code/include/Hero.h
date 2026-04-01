#ifndef HERO_H
#define HERO_H

#include"Character.h"

void H_setHero(void);
C_Character *H_getHeroInfo(void);
C_Position *H_getHeroPos(void);
int H_isTop(C_Position *p);
int H_isBottom(C_Position *p);
int H_isLeftEdge(C_Position *p);
int H_isRightEdge(C_Position *p);
//void H_Moving(C_Position *p, char key);
int H_Attack(C_Character *e);
void H_Hurted();
void H_addHP(int add);
void H_addDefence(int add);
void H_addStrength(int add);

#endif

#ifndef CHARACTER_H
#define CHARACTER_H

typedef enum
{
    male = 0,
    female = 1,
    NA = 2 
} C_GenderType;

typedef enum
{
    EM = 0,
    FlyingCannon,
    VampireTooth,
    HeartProtection
    //共个
} C_EquipmentType;//C_getEquipmentDscp, C_Equipment**,  M_showEquipmentMenu(in main)

typedef struct 
{
    char name_EN[20];
    char name_CN[20];
    C_GenderType gender;
    int HP;
    int max_HP;
    int hurt;
    int strength;
    int wisdom;
    int defence;

    C_EquipmentType equipment[3];
} C_Character;

typedef enum
{
    w = 'w', d = 'd', s = 's', a = 'a'
} C_DirectionType;

typedef struct 
{
    int x;
    int y;
    C_DirectionType direction;
} C_Position;

int C_randomNum(int max);
void C_initEnemy(void);
C_Character *C_getBossInfo(void);
C_Character *C_getEnemyInfo(void);
int C_Attack(C_Character *p1, C_Character *p2);
void C_Hurted(C_Character *p);
void C_addHP(C_Character *p, int add);
void C_addDefence(C_Character *p, int add);
void C_addStrength(C_Character *p, int add);
int C_enemyAction(C_Character *e, C_Character *h);
void C_getEquipmentDscp(C_EquipmentType eq);
void C_EquipmentBB(C_Character *h, C_Character *e);
void C_EquipmentCD(C_Character *h, C_Character *e);
void C_EquipmentAB(C_Character *h, C_Character *e);

#endif

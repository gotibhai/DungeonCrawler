#ifndef __POTION_H__
#define __POTION_H__

#include "PotionType.cc"
#include "CellType.cc"

class Potion{ 
    PotionType potionType;
    int value;
  public:
  	Potion(PotionType, int);
    int getHp();
    int getDef();
    int getAtk();
    PotionType getPotionType();
    void setValue(int);
    int getValue();
};

#endif

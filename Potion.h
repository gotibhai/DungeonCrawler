#ifndef __POTION_H__
#define __POTION_H__
#include "PotionType.cc"

class Potion {
  private:
    PotionType potionType;
    int value;
  public:
    int getHp();
    int getDef();
    int getAtk();
    void setValue(int);
};

#endif

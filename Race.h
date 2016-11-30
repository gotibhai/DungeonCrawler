#ifndef __RACE_H__
#define __RACE_H__
// #include "CellType.cc"
#include "Character.h"
#include "Potion.h"
#include <vector>


class Race: public Character {
private:
  int totalGold;
  std::vector<Potion> potions;
public:
  Race(int, int , int, CellType);
  int getTotalGold();
  virtual void use(Potion);
  // void use(Gold);
  int getDef() override;
  int getAtk() override;
  void resetPotions();
};

#endif

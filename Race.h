#ifndef __RACE_H__
#define __RACE_H__
// #include "CellType.cc"
#include "Character.h"
#include "Potion.h"
#include "Cell.h"
#include <vector>


class Race: public Character {
private:
  int totalGold;
  std::vector<class Potion> potions;
public:
  Race(int, int , int);
  int getTotalGold();
  virtual void use(class Potion);
  // void use(Gold);
  int getDef() override;
  int getAtk() override;
  void resetPotions();
  bool attack(Character*) override;
};

#endif

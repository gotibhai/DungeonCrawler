#ifndef __Character_H__
#define __Character_H__

#include "Cell.h"

class Character: public Cell {
private:
  int maxHp;
  int hp;
  int atk;
  int def;
public:
  Character(int, int, int, int);
  bool move(Direction);
  bool attack(Character*);
  void die();
  void winBattle();
  int getHp();
  int getAtk();
  int getDef();
  void setHp(int);
};

#endif

#ifndef __Character_H__
#define __Character_H__

#include "Cell.h"
#include "Direction.cc"
// #include "CellType.cc"

class Character: virtual public Cell {
private:
  int maxHp;
  int hp;
  int atk;
  int def;

  virtual bool willAttackSucceed(Character*) = 0;
public:
  Character(int, int, int);
  virtual void attack(Character*);
  virtual void die() = 0;
  virtual void winBattle();
  virtual int getAtk();
  virtual int getDef();
  int getHp();
  void setHp(int);
};

#endif

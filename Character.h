#ifndef __Character_H__
#define __Character_H__

#include "Cell.h"
#include "Direction.cc"
// #include "CellType.cc"

class Character: public Cell {
private:
  int maxHp;
  int hp;
  int atk;
  int def;
public:
  Character(int, int, int, CellType);
  virtual bool move(Direction);
  virtual bool attack(Character*);
  void die();
  virtual void winBattle();
  int getHp();
  virtual int getAtk();
  virtual int getDef();
  void setHp(int);
};

#endif

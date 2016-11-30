#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Enemy: public Character {
private:
  bool isHostile;
public:
  Enemy(int, int, int, CellType, bool);
  void setIsHostile(bool);
  bool getIsHostile();
};

#endif

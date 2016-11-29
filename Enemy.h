#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Enemy: public Character {
private:
  bool isHostile;
public:
  Enemy(int, int, int, int);
  void setIsHostile(bool);
  bool getIsHostile();
};

#endif

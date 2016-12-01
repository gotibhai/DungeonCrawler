#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Enemy: virtual public Character {
private:
  bool isHostile;
public:
  Enemy(int, int, int, bool isHostile = true);
  void setIsHostile(bool);
  bool getIsHostile();
  bool attack(Character*) override;
};

#endif

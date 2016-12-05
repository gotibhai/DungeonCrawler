#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Enemy: virtual public Character {
private:
  bool isHostile;
  bool willAttackSucceed(Character* defender);
public:
  Enemy(bool isHostile = true);
  void setIsHostile(bool);
  virtual bool getIsHostile();
  virtual void die() ;
};

#endif

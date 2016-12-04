#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Character.h"

class Enemy: virtual public Character {
private:
  bool isHostile;
public:
  Enemy(bool isHostile = true);
  void setIsHostile(bool);
  bool getIsHostile();
  void die();
  virtual bool attack(Character*) override;
};

#endif

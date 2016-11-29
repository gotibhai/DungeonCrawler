#ifndef __ORC_H__
#define __ORC_H__
#include "Enemy.h"
#include "Character.h"

class Orc: public Enemy {
public:
  Orc(int, int, int, int);
  bool attack(Character*) override;
};

#endif

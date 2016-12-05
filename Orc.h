#ifndef __ORC_H__
#define __ORC_H__
#include "Enemy.h"
#include "Character.h"

class Orc: public Enemy {
public:
  Orc();
  void attack(Character*) override;
};

#endif

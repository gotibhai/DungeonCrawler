#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "Enemy.h"
#include "Gold.h"

class Human: public Enemy, public Gold {
public:
  Human();
  void reset();
  bool canMoveOn(Character*) override;
};

#endif

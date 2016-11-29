#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "Enemy.h"
#include "Gold.h"

class Human: public Enemy, public Gold {
public:
  Human(int, int, int, int);
  void reset() override;
};

#endif

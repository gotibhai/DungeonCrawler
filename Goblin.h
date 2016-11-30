#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "Race.h"
#include "CellType.cc"

class Goblin: public Race {
public:
  Goblin();
  void winBattle() override;
};

#endif

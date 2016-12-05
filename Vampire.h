#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "Race.h"
#include "CellType.cc"
#include "Character.h"

class Vampire: public Race {
public:
  Vampire();
  void attack(Character*) override;

};

#endif

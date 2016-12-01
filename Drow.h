#ifndef __DROW_H__
#define __DROW_H__

#include "Race.h"
#include "CellType.cc"
#include "Potion.h"

class Drow: public Race {
public:
  Drow();
  void use(class Potion) override;
};

#endif

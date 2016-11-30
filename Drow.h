#ifndef __DROW_H__
#define __DROW_H__

#include "Race.h"
#include "CellType.cc"
#include "Potion.h"

class Drow: public Race {
public:
  Drow(CellType);
  void use(Potion) override;
};

#endif

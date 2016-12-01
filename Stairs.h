#ifndef __STAIR_H__
#define __STAIR_H__

#include "Cell.h"
#include "Direction.cc"
#include "ActionItem.cc"
// #include "CellType.cc"

class Stairs: public ActionItem {
  public:
    Stairs();
    void use();
};

#endif

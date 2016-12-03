#ifndef __STAIR_H__
#define __STAIR_H__

#include "ActionItem.h"
// #include "CellType.cc"

class Stairs: public ActionItem {
  public:
    Stairs(): Cell{CellType::Stairs} { };
};

#endif

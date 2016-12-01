#ifndef __ACTION_ITEM_H__
#define __ACTION_ITEM_H__

#include "Cell.h"
#include "Character.h"
#include "CellType.cc"

class ActionItem: virtual public Cell {
public:
  ActionItem();
  virtual bool canMoveOn(Character*) override;
  virtual void use() = 0;
};

#endif

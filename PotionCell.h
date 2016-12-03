#ifndef __POTIONCELL_H__
#define __POTIONCELL_H__

#include "Potion.h"
#include "Cell.h"
#include "ActionItem.h"

class PotionCell: public ActionItem {
	class Potion potion;
public:
	PotionCell(class Potion potion): potion{potion}, Cell(CellType::Potion){}
	class Potion getPotion();
};



#endif
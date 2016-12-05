#ifndef __POTIONCELL_H__
#define __POTIONCELL_H__

#include "Potion.h"
#include "Cell.h"
#include "ActionItem.h"

class PotionCell: public ActionItem {
	Potion potion;
public:
	PotionCell(Potion potion): potion{potion}, Cell(CellType::PotionC){}
	Potion getPotion();
};



#endif

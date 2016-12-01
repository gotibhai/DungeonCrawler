#ifndef __POTIONCELL_H__
#define __POTIONCELL_H__

#include "Potion.h"
#include "Cell.h"

class PotionCell : public Cell{
	class Potion *potion;
public:
	PotionCell(class Potion*):Cell(CellType::Potion){}
	class Potion* getPotion();
	bool usePotion();
};



#endif
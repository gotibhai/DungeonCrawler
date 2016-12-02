#ifndef __GOLD_H__
#define __GOLD_H__

#include "GoldType.cc"
#include "Cell.h"
#include "ActionItem.h"

class Gold : virtual public ActionItem {
	GoldType goldtype;
	bool isCollectible;
	public: 
		Gold(GoldType g): Cell{CellType::Gold} { 
			goldtype = g; 
		}
		void use();
		GoldType getType();
		void setIsCollectible(bool);
};

#endif

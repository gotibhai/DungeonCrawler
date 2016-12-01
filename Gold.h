#ifndef __GOLD_H__
#define __GOLD_H__

#include "GoldType.cc"
#include "Cell.h"
//#include "ActionItem.h"

class Gold : public Cell {
	GoldType goldtype;
	bool isCollectible;
	public: 
		Gold(GoldType g): Cell(CellType::Gold) { goldtype = g; }
		bool use();
		void setIsCollectible(bool);
};

#endif

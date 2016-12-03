#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "CellType.cc"
class Character;

class Cell {
	private:
	    int row;
	    int col;
	    CellType type;
	    CellType cellTypeCovered;
	public:
		Cell();
		Cell(CellType);
		virtual bool canMoveOn(Character* character);
		void setCoords(int row, int col);
		char getSymbol() const;
		int getRow();
		int getCol();
		CellType getType() const;
		void reset();
		void setType();
		void setCellTypeCovered(CellType cellType);
		void setIsFrozen(bool setIsFrozen);
		CellType getCellTypeCovered();
		friend std::ostream &operator<<(std::ostream &out, const Cell &g);
};

#endif

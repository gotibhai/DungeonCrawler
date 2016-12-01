#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <string>
#include "CellType.cc"

class Cell {
	private:
	    int row;
	    int col;
	    CellType type;
	public:
		Cell(CellType);
		// bool canMoveOnm(Character* character);
		void setCoords(int row, int col);
		char getSymbol() const;
		int getRow();
		int getCol();
		void reset();
		void setType();
		friend std::ostream &operator<<(std::ostream &out, const Cell &g);
};

#endif

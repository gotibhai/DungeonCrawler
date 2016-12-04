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
	    Cell* cellCovered;
	public:
		Cell();
		~Cell();
		Cell(CellType);
		virtual bool canMoveOn(Character* character);
		void setCoords(int row, int col);
		char getSymbol() const;
		int getRow();
		int getCol();
		CellType getType() const;
		void reset();
		void setType();
		void setCellCovered(Cell* cell);
		Cell* getCellCovered();
		friend std::ostream &operator<<(std::ostream &out, const Cell &g);
};

#endif

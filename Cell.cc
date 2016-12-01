#include <iostream>
#include <string>
#include "Cell.h"
#include "CellType.cc"

Cell::Cell(): type{CellType::Empty} {};
Cell::Cell(CellType type): type{type} {};
void Cell::setCoords(int row, int col) {this->row = row; this->col = col;};
CellType Cell::getType() const { return type; };
int Cell::getRow() { return row; };
int Cell::getCol() { return col; };
void Cell::reset() {};

char Cell::getSymbol() const { 
	if((char) type == 's' || (char) type == 'd' || (char) type == 'v' || (char) type == 't'|| (char) type == 'g'){
		return '@';
	} else {
		return (char) type;
	}

};

bool Cell::canMoveOn(Character* character) { 
	return this->getType() == CellType::Ground; 
}



std::ostream &operator<<(std::ostream &out, const Cell &g) {
	out << g.getSymbol();
	return out;
};


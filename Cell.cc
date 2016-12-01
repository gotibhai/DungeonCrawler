#include <iostream>
#include <string>
#include "Cell.h"
#include "CellType.cc"

Cell::Cell(CellType type): type{type} {};
bool Cell::canMoveOn(Character* character) { return false };
void Cell::setCoords(int row, int col) {this->row = row; this->col = col;};
char Cell::getSymbol() const { return (char) type; };
CellType Cell::getType() const { return type; };
int Cell::getRow() { return row; };
int Cell::getCol() { return col; };
void Cell::reset() {};

std::ostream &operator<<(std::ostream &out, const Cell &g) {
	out << g.getSymbol();
	return out;
};


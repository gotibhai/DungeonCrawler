#include <iostream>
#include <string>
#include "Cell.h"
#include "CellType.cc"
#include "Race.h"

using namespace std;

Cell::Cell(): type{CellType::Empty}, cellTypeCovered{CellType::Ground} {};
Cell::Cell(CellType type): type{type}, cellTypeCovered{CellType::Ground} {};
void Cell::setCoords(int row, int col) {this->row = row; this->col = col;};
CellType Cell::getType() const { return type; };
int Cell::getRow() { return row; };
int Cell::getCol() { return col; };
void Cell::reset() { type == CellType::Ground; };

char Cell::getSymbol() const { 
	if((char) type == 's' || (char) type == 'd' || (char) type == 'v' || (char) type == 't'|| (char) type == 'g'){
		return '@';
	} else {
		return (char) type;
	}

};

bool Cell::canMoveOn(Character* character) { 
	cout << "can " << (char) character->getType() << " MoveOn " << (char) this->getType() << endl;
	return (this->getType() == CellType::Ground || 
		(dynamic_cast<class Race*>(character) && (this->getType() == CellType::Bridge || this->getType() == CellType::BridgeEnter)));
}

void Cell::setCellTypeCovered(CellType cellType) { cellTypeCovered = cellType; }
CellType Cell::getCellTypeCovered() {return cellTypeCovered;}


std::ostream &operator<<(std::ostream &out, const Cell &g) {
	out << g.getSymbol();
	return out;
};


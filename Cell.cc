#include <iostream>
#include <string>
#include "Cell.h"
#include "CellType.cc"
#include "Race.h"
#include "Game.h"

using namespace std;

Cell::Cell(): type{CellType::Empty} {};
Cell::Cell(CellType type): type{type}, cellCovered{new Cell()} {
};
Cell::~Cell() {
	delete cellCovered;
}
void Cell::setCoords(int row, int col) {this->row = row; this->col = col;};
CellType Cell::getType() const { return type; };
int Cell::getRow() { return row; };
int Cell::getCol() { return col; };

char Cell::getSymbol() const {
	if((char) type == 's' || (char) type == 'd' || (char) type == 'v' || (char) type == 't'|| (char) type == 'g'){
		return '@';
	} else {
		return (char) type;
	}
};

bool Cell::canMoveOn(Character* character) {
	//cout << "can " << (char) character->getType() << " MoveOn " << (char) this->getType() << endl;
	return (this->getType() == CellType::Ground ||
		(dynamic_cast<class Race*>(character) && (this->getType() == CellType::Bridge || this->getType() == CellType::BridgeEnter)));
}

void Cell::reset() {
	//cout << "Cell::reset" << endl;
	Cell *prevCell = cellCovered;
	if (prevCell->getType() == CellType::Empty) {
		//cout << "Cell::reset == NULL 1" << endl;
		prevCell = new Cell(CellType::Ground);
		prevCell->setCoords(getRow(), getCol());
		//cout << "Cell::reset == NULL" << endl;
	}
	//cout << "Cell::reset 2 " << prevCell->getType() << " row: " << prevCell->getRow() << " " << prevCell->getCol() << endl;

	Game::getInstance()->getCurrentGrid()->setCell(prevCell);
}



void Cell::setCellCovered(Cell* cell) { cellCovered = cell; }
Cell* Cell::getCellCovered() {return cellCovered;}


std::ostream &operator<<(std::ostream &out, const Cell &g) {
	out << g.getSymbol();
	return out;
};

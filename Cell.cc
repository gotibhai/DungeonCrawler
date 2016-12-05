#include <iostream>
#include <string>
#include "Cell.h"
#include "CellType.cc"
#include "Race.h"
#include "Game.h"

using namespace std;

Cell::Cell(): type{CellType::Empty}, cellCovered{NULL} {};
Cell::Cell(CellType type): type{type}, cellCovered{new Cell()} {
};
Cell::~Cell() {
	cout<<"Cell's destructor"<<endl;
	cout<<getSymbol()<<endl;

	if (cellCovered != NULL) {
		delete cellCovered;
	}
	cellCovered = nullptr;
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
	return (this->getType() == CellType::Ground ||
		(dynamic_cast<class Race*>(character) && (this->getType() == CellType::Bridge || this->getType() == CellType::BridgeEnter)));
}

void Cell::reset() {
	Cell *prevCell = cellCovered;
	Game::getInstance()->getCurrentGrid()->removeEnemy(dynamic_cast<class Enemy*>(prevCell));
	if (prevCell->getType() == CellType::Empty) {
		prevCell = new Cell(CellType::Ground);
		prevCell->setCoords(getRow(), getCol());
	}
	Game::getInstance()->getCurrentGrid()->setCell(prevCell);
	prevCell = nullptr;
}

void Cell::setCellCovered(Cell* cell) { cellCovered = cell; }
Cell* Cell::getCellCovered() {return cellCovered;}

std::ostream &operator<<(std::ostream &out, const Cell &g) {
	out << g.getSymbol();
	return out;
};

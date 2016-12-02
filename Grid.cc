#include "Grid.h"
#include "Stairs.h"
#include "CellType.cc"
#include "Race.h"
#include "Gold.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

Grid::Grid(){
	// Constructor for Grid
};

Grid::~Grid() {
	// Destroy cells and enemies
};

void Grid::setCell(Cell *cell) { grid[cell->getRow()][cell->getCol()] = cell; };
void Grid::setEnemies(std::vector<Enemy*> enemy_vector ) { this->enemies = enemy_vector ;};

bool firstTime = true;

bool Grid::move(Character *character, Direction direction) {
	int row = character->getRow();
	int col = character->getCol();

	if (direction == Direction::NO || direction == Direction::NE || direction == Direction::NW) {
		row -= 1;
	}
	if (direction == Direction::SO || direction == Direction::SE || direction == Direction::SW) {
		row += 1;
	}
	if (direction == Direction::WE || direction == Direction::SW || direction == Direction::NW) {
		col -= 1;
	}
	if (direction == Direction::EA || direction == Direction::SE || direction == Direction::NE) {
		col += 1;
	}

	Cell *cell = grid[row][col];
	CellType type = cell->getType();
	if (!cell->canMoveOn(character)) {
		return false;
	}

	if (dynamic_cast<Race*>(character)) {
		switch(cell->getType()) {
			case(CellType::Gold):
				(dynamic_cast<class Gold*>(cell))->use();
				break;
			case(CellType::Stairs):
				(dynamic_cast<class Stairs*>(cell))->use();
				break;
		}
	}
	Cell *emptyCell = new Cell(CellType::Ground);
	emptyCell->setCoords(character->getRow(), character->getCol());
	character->setCoords(row, col);

	setCell(emptyCell);
	setCell(character);

	return true;

};

Cell* Grid::getCell(int r, int c) {
	return grid[r][c];
}

// bool Grid::attack(Character *character, Direction direction) {
// 	return true;
// };

// void Grid::start(Race *player) {
// 	// 1. Find empty cell and assign player related coords
// 	// 2. Place cell respectivelly

// 	setCell(player);
// };
void Grid::moveEnemies() {
	if (isFrozen) {
		return;
	}

	const int totalDirections = 8;

	for (int i = 0; i < Grid::MAX_ENEMIES; i++) {
		bool isMoved = false;
		vector<Direction> directions;
		Direction direction;
		while (!isMoved) {
			Direction direction;
			int dir = rand() % (totalDirections);
			direction = (Direction)dir;
			while (std::find(directions.begin(), directions.end(), direction) != directions.end()) {
				direction = static_cast<Direction>(rand() % totalDirections);
			}
			isMoved = move(enemies[i], direction);
			directions.push_back(direction);
		}
	}
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
	for (int i = 0; i < Grid::GRID_HEIGHT; i++) {
		for (int j = 0; j < Grid::GRID_WIDTH; j++) {
			out << g.grid[i][j]->getSymbol();
		}
		out << '\n';
	}
	return out;
}

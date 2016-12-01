#include "Grid.h"
#include "Stairs.h"
#include "CellType.cc"
#include "Race.h"
#include "Gold.h"
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include <iostream>
using namespace std;

Grid::Grid(){
	// Constructor for Grid
};

Grid::~Grid() {
	// Destroy cells and enemies
};

void Grid::setCell(Cell *cell) { grid[cell->getRow()][cell->getCol()] = cell; };
void Grid::setEnemies(Enemy** enemies) { this->enemies = enemies; };

bool Grid::move(Character *character, Direction direction) {
	int row = character->getRow();
	int col = character->getCol();

	if (direction == NO || direction == NE || direction == NW) {
		row += 1;
	}
	if (direction == SO || direction == SE || direction == SW) {
		row -= 1;
	}
	if (direction == WE || direction == SW || direction == NW) {
		col -= 1;
	}
	if (direction == EA || direction == SE || direction == NE) {
		col += 1;
	}

	Cell *cell = grid[row][col];
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

	

	return true;
};

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
		while (!isMoved) {
			Direction direction;
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

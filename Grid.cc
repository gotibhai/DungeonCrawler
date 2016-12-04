#include "Grid.h"
#include "Stairs.h"
#include "CellType.cc"
#include "Race.h"
#include "Gold.h"
#include "PotionCell.h"
#include "Game.h"
#include "Logger.h"
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

Cell* Grid::getCellByDirection(Cell *cell, Direction direction) {
	int row = cell->getRow();
	int col = cell->getCol();

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

	return grid[row][col];
}

bool Grid::move(Character *character, Direction direction) {
	Cell *cell = getCellByDirection(character, direction);
	//cout << "Grid::move character" << (char) character->getType() << endl;
	//cout << "Grid::move cell" << (char) cell->getType() << endl;
	if (!cell->canMoveOn(character)) {
		return false;
	}
	//cout << "Grid::move 2" << (char) character->getType() << endl;
	
	if (dynamic_cast<class Race*>(character)) {
		//cout << "Grid::move isRace " << (char) character->getType() << endl;
		switch(cell->getType()) {
			case(CellType::Stairs):
			case(CellType::Gold):
				Game::getInstance()->use(dynamic_cast<class ActionItem*>(cell));
				cell = getCellByDirection(character, direction);
				if(CellType::Stairs) {
						return true;
				}
				break;
		}
		isFrozen = false;

		Logger::getInstance()->move(direction, getObjectsNearby(dynamic_cast<class Race*>(character)));
	}
	//cout << "Grid::move 3" << (char) character->getType() << endl;

	character->reset();	
	//cout << "Grid::move 4" << (char) character->getType() << endl;


	character->setCellCovered(cell);
	character->setCoords(cell->getRow(), cell->getCol());
	setCell(character);
	//cout << "Grid::move 5" << (char) character->getType() << endl;
	// bridge

	//cout << "Grid::move 6" << (char) character->getType() << endl;

	return true;
};

vector<Cell*> Grid::getObjectsNearby(Cell* player) {
	vector<Cell*> cells;
	for (int row = player->getRow()-1; row <= player->getRow() + 1; row++ ) {
		for (int col = player->getCol()-1; col <= player->getCol() + 1; col++ ) {
			if ((!(row == player->getRow() && col == player->getCol())) &&
				(dynamic_cast<class Character*>(grid[row][col]) || 
					dynamic_cast<class ActionItem*>(grid[row][col]))) {
				cells.push_back(grid[row][col]);
			}
		}
	}
	return cells;
}

Cell* Grid::getCell(int r, int c) {
	return grid[r][c];
}


bool Grid::action(Action action, Race* player, Direction direction) {
  switch (action) {
    case Action::ATTACK:
    	return attack(player, direction);
    case Action::MOVE:
    	return move(player, direction);
    case Action::USE_POTION:
    	return usePotion(player, direction);
    default:
      return false;
  }
}

bool Grid::usePotion(Race *player, Direction direction) {
	Cell *cell = getCellByDirection(player, direction);
	cout << "Grid::usePotion cell " << (char) cell->getType() << endl;
	if (dynamic_cast<class PotionCell*>(cell)) {
		cout << "Grid::usePotion use " << (char) cell->getType() << endl;
		Game::getInstance()->use(dynamic_cast<class PotionCell*>(cell));
		cout << "Grid::usePotion after use " << (char) cell->getType() << endl;
		cell->reset();
		return true;
	}
	return false;
}

bool Grid::attack(Race *character, Direction direction) {
	Cell *cell = getCellByDirection(character, direction);

	isFrozen = true;

	if (dynamic_cast<class Enemy*>(cell)) {
		attack(character, dynamic_cast<class Enemy*>(cell));
		return true;
	}

	return false;
};

bool Grid::attack(Character *character1, Character *character2) {
	isFrozen = true;
	return character1->attack(character2);
};

// void Grid::start(Race *player) {
// 	// 1. Find empty cell and assign player related coords
// 	// 2. Place cell respectivelly

// 	setCell(player);
// };

Race* Grid::getPlayerNearby(Enemy* enemy) {
	for (int row = enemy->getRow()-1; row <= enemy->getRow() + 1; row++ ) {
		for (int col = enemy->getCol()-1; col <= enemy->getCol() + 1; col++ ) {
			if (dynamic_cast<class Race*>(grid[row][col])) {
				return dynamic_cast<class Race*>(grid[row][col]);
			}
		}
	}
	return nullptr;
}



void Grid::setIsFrozen(bool isFrozen) {
	this->isFrozen = isFrozen;
	isFrozenByUserControl = isFrozen;
}

void Grid::moveEnemy(Enemy *enemy) {
	bool isMoved = false;
	vector<Direction> directions;
	Direction direction;
	while (!isMoved) {
		// Question here
		Direction direction = (Direction) (rand() % Direction::TOTAL);
		while (std::find(directions.begin(), directions.end(), direction) != directions.end()) {
			direction = (Direction) (rand() % Direction::TOTAL);
		}
		cout << direction << endl;
		directions.push_back(direction);
		isMoved = move(enemy, direction);
	}
}

void Grid::enemiesMove() {
	if (!isFrozen) {
		for (int i = 0; i < Grid::MAX_ENEMIES; i++) {
			moveEnemy(enemies[i]);
		}
	}
	for (int i = 0; i < Grid::MAX_ENEMIES; i++) {
		Race *player = getPlayerNearby(enemies[i]);

		if (player) {
			attack(enemies[i], player);
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

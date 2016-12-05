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
	enemies.clear();
	cout<<"Grid's destructor"<<endl;
	for(int i = 0; i<GRID_HEIGHT; i++) {
		for(int j = 0; j<GRID_WIDTH; j++) {
			delete grid[i][j];
		}
	}

	// delete grid;
};

void Grid::removeEnemy(Enemy *enemy) {
	int len = this->enemies.size();
	for(int i = 0; i<len; i++) {
		if(this->enemies[i] == enemy) {
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

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
	if (!cell->canMoveOn(character)) {
		return false;
	}
	if (dynamic_cast<class Race*>(character)) {
		switch(cell->getType()) {
			case(CellType::Stairs):
			case(CellType::Gold):
				if(cell->getType() == CellType::Gold && !(dynamic_cast<class Gold*>(cell)->getIsCollectible())) {
						return false;
				}
				Game::getInstance()->use(dynamic_cast<class ActionItem*>(cell));
				if(cell->getType() == CellType::Stairs) {
						return true;
				}
				cell = getCellByDirection(character, direction);
				break;
		}
		isFrozen = false;

		Logger::getInstance()->move(direction, getObjectsNearby(dynamic_cast<class Race*>(character)));
	}

	character->reset();

	character->setCellCovered(cell);
	character->setCoords(cell->getRow(), cell->getCol());
	setCell(character);
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
	if (dynamic_cast<class PotionCell*>(cell)) {
		Game::getInstance()->use(dynamic_cast<class PotionCell*>(cell));
		cell->reset();
		return true;
	}
	return false;
}

bool Grid::attack(Race *character, Direction direction) {
	Cell *cell = getCellByDirection(character, direction);

	if (dynamic_cast<class Enemy*>(cell)) {
		attack(character, dynamic_cast<class Enemy*>(cell));
		return true;
	}

	return false;
};

void Grid::attack(Character *character1, Character *character2) {
	isFrozen = true;
	character1->attack(character2);
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
	while (!isMoved && directions.size() < Direction::TOTAL) {
		// Question here
		Direction direction = Direction::TOTAL;
		while (direction == Direction::TOTAL || std::find(directions.begin(), directions.end(), direction) != directions.end()) {
			direction = (Direction) (rand() % Direction::TOTAL);
		}
		directions.push_back(direction);
		isMoved = move(enemy, direction);
	}
}

void Grid::enemiesMove() {
	if (!isFrozen) {
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i]->getType() != CellType::Dragon) {
				moveEnemy(enemies[i]);
			}
		}
	}
	for (int i = 0; i < enemies.size(); i++) {
		Race *player = getPlayerNearby(enemies[i]);

		if (player && enemies[i]->getIsHostile()) {
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

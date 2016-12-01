#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <string>
#include "Direction.cc"
#include "Cell.h"
#include "Enemy.h"

class Cell;

class Grid {
	private:
		const static int GRID_WIDTH = 79;
		const static int GRID_HEIGHT = 25;
		const static int MAX_ENEMIES = 20;

	    Cell* grid[GRID_HEIGHT][GRID_WIDTH];
	    Enemy** enemies;
	    bool isFrozen;
	public:
		Grid();
		~Grid();
		void setCell(Cell *cell);
		void setEnemies(Enemy** enemies);
		bool move(Character *character, Direction direction);
		// bool attack(Character *character, Direction direction);
		// void start(Race *player);
		void moveEnemies();
		friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif

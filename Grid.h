#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <string>
#include "Direction.cc"
#include "Cell.h"
#include <vector>
#include "Enemy.h"
#include "Race.h"
#include "Action.cc"

class Cell;

class Grid {
	private:
		const static int GRID_WIDTH = 79;
		const static int GRID_HEIGHT = 25;
		const static int MAX_ENEMIES = 20;

	    Cell* grid[GRID_HEIGHT][GRID_WIDTH];
	    std::vector<Enemy*> enemies;
	    bool isFrozen;
	    bool isFrozenByUserControl;

	    Race* getPlayerNearby(Enemy* enemy);
	    bool attack(Character*, Character*);
	    void moveEnemy(Enemy *enemy);
	    bool move(Character *character, Direction direction);
		bool attack(Race *character, Direction direction);
		bool usePotion(Race *character, Direction direction);
		Cell* getCellByDirection(Cell *cell, Direction direction);
		std::vector<Cell*> getObjectsNearby(Cell* player);

	public:
		Grid();
		~Grid();
		void setCell(Cell *cell);
		void setEnemies(std::vector<Enemy*>);
    	bool action(Action, Race*, Direction);
    	void setIsFrozen(bool setIsFrozen);
		Cell* getCell(int r, int c);
		void enemiesMove();
		friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif

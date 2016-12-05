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
	public:
		const static int GRID_WIDTH = 79;
		const static int GRID_HEIGHT = 25;
		const static int MAX_ENEMIES = 20;

		Grid();
		~Grid();
		void setCell(Cell *cell);
		void setEnemies(std::vector<Enemy*>);
		Cell* getCellByDirection(Cell *cell, Direction direction);
  		bool action(Action, Race*, Direction);
  		void setIsFrozen(bool setIsFrozen);
		Cell* getCell(int r, int c);
		void enemiesMove();
		void removeEnemy(Enemy*);
		friend std::ostream &operator<<(std::ostream &out, const Grid &g);

	private:
	    Cell* grid[GRID_HEIGHT][GRID_WIDTH];
	    std::vector<Enemy*> enemies;
	    bool isFrozen;
	    bool isFrozenByUserControl;

	    Race* getPlayerNearby(Enemy* enemy);
	    void attack(Character*, Character*);
	    void moveEnemy(Enemy *enemy);
	    bool move(Character *character, Direction direction);
		bool attack(Race *character, Direction direction);
		bool usePotion(Race *character, Direction direction);
		std::vector<Cell*> getObjectsNearby(Cell* player);

	
};

#endif

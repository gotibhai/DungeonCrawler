#ifndef __CELLFACTORY_H__
#define __CELLFACTORY_H__

#include "Grid.h"
#include "Race.h"
#include <string>
#include <vector>


class CellFactory {
	const static int TOTAL_CHAMBERS;
	std::vector<std::vector<Cell*>> chambers;
	std::vector<Enemy*> enemy_vector;
	Grid* grid;
	Cell* getCell(char);
	Cell* getGoldCell(int);
	Cell* getPotionCell(int);
	void place(Cell*);
	std::vector<Enemy *> generateEnemies();
	std::vector<Cell> generateCells();
	std::vector<Cell *> generateRandPotions();
	std::vector<Cell *> getRandomGoldCell();
	void setCellNearby(Cell* newcell);

public:
	//CellFactory();
	~CellFactory();
	Grid* GenerateGridFromFile(std::string filename , Race* player, int floor = 0);

	//Race* getRace(char racetype);
};




#endif

#ifndef __CELLFACTORY_H__
#define __CELLFACTORY_H__

#include "Grid.h"
#include "Race.h"
#include <string>
#include <vector>


class CellFactory{
	Cell* getCell(char);
	Cell* getGoldCell(int);
	Cell* getPotionCell(int);
	std::vector<Enemy *> generateEnemies();
	std::vector<Cell> generateCells();
	std::vector<Cell *> generateRandPotions();
	std::vector<Cell *> getRandomGoldCell();

public:
	// CellFactory();
	// ~CellFactory();
	Grid* GenerateGridFromFile(std::string filename , Race* player);
	//Race* getRace(char racetype);
};

#endif
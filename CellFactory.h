#ifndef __CELLFACTORY_H__
#define __CELLFACTORY_H__

#include "Cell.h"
#include "Grid.h"
#include <string>
#include <vector>


class CellFactory{
	Cell* getCell(char);
	Cell* getGoldCell(int);
	Cell* getPotionCell(int);
	std::vector<Cell *> generateEnemies();
	std::vector<Cell> generateCells();

public:
	// CellFactory();
	// ~CellFactory();
	Grid* GenerateGridFromFile(std::string filename);
	//Race* getRace(char racetype);
};

#endif
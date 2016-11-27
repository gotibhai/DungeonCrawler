#include "Grid.h"

Grid::Grid() {};
Grid::~Grid() {
	// Destroy cells and enemies
};

void Grid::setCell(Cell *cell) { grid[cell->getRow()][cell->getCol()] = cell; };
// void Grid::setEnemies(Enemy** enemies) { this->enemies = enemies };

// bool Grid::move(Character *character, Direction direction) {
// 	return true;
// };

// bool Grid::attack(Character *character, Direction direction) {
// 	return true;
// };

// void Grid::start(Race *player) {
// 	// 1. Find empty cell and assign player related coords
// 	// 2. Place cell respectivelly

// 	setCell(player);
// };
void Grid::moveEnemies() {};
std::ostream &operator<<(std::ostream &out, const Grid &g);

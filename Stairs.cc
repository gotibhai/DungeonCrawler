#include "Stairs.h"
#include "Game.h"
#include "CellType.cc"

Stairs::Stairs(){};
void Stairs::use() {
	Game::getInstance()->nextFloor();
};



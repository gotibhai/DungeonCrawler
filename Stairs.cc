#include "Stairs.h"
#include "Game.h"
#include "CellType.cc"

void Stairs::use() {
	Game::getInstance()->nextFloor();
};



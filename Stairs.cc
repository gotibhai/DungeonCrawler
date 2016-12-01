#include "Stairs.h"
#include "Game.h"
#include "CellType.cc"

Stairs::Stairs(): ActionItem(CellType::Stairs) {};
void Stairs::use() {
	Game::getInstance()->nextFloor();
};



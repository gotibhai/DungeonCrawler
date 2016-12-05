#include "Human.h"
#include "Gold.h"
#include "GoldType.cc"

Human::Human(): Character{140, 20, 20}, Gold{GoldType::SmallGold}, Cell{CellType::Human} {}

void Human::die() {
	Gold *gold = new Gold(GoldType::NormalGold);
	gold->setCoords(getRow(), getCol());
	setCellCovered(gold);
	Enemy::die();
}

bool Human::canMoveOn(Character*) {
	return false;
}


#include "Human.h"

Human::Human(): Character{140, 20, 20}, Gold{GoldType::SmallGold}, Cell{CellType::Human} {}

void Human::reset() {

}

bool Human::canMoveOn(Character*) {
	return false;
}


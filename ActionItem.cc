#include "ActionItem.h"

ActionItem::ActionItem(CellType cellType): Cell{cellType} {}
bool ActionItem::canMoveOn(Character* cell) {
	return false;
}

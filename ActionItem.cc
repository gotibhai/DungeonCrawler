#include "ActionItem.h"
#include "Race.h"

ActionItem::ActionItem(){}
bool ActionItem::canMoveOn(Character* character) {
	return dynamic_cast<class Race*>(character);
}

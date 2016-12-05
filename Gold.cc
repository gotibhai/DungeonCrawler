#include "Gold.h"

void Gold::setIsCollectible(bool isCollectible) {
  this->isCollectible = isCollectible;
}

bool Gold::canMoveOn() {
  return this->isCollectible;
}

GoldType Gold::getGoldType(){
	return goldtype;
}

bool Gold::getIsCollectible() {
  return isCollectible;
}

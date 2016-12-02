#include "Gold.h"

void Gold::use() {
  
}
void Gold::setIsCollectible(bool isCollectible) {
  this->isCollectible = isCollectible;
}

bool Gold::getIsCollectible() {
  return this->isCollectible;
}

GoldType Gold::getType(){
	return goldtype;
}
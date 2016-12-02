#include "Gold.h"

void Gold::use() {
  
}
void Gold::setIsCollectible(bool isCollectible) {
  this->isCollectible = isCollectible;
}

GoldType Gold::getType(){
	return goldtype;
}
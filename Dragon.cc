#include "Dragon.h"
#include "Enemy.h"

Dragon::Dragon(class Gold* g): Character{150, 20, 20}, Cell{CellType::Dragon} {gold = g;}


void Dragon::die(){
	gold->setIsCollectible(true);
	Enemy::die();
}

Dragon::~Dragon() {
  delete gold;
}

// bool Dragon::move(Direction direction) {
//   return false;
// }

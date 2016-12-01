#include "Enemy.h"
#include "CellType.cc"
#include <stdlib.h>

Enemy::Enemy(int maxHp, int atk, int def, bool isHostile): Character{maxHp, atk, def}, Cell{CellType::Empty}, isHostile{isHostile} {}

void Enemy::setIsHostile(bool hostility) {
  isHostile = hostility;
}
bool Enemy::getIsHostile() {
  return isHostile;
}
bool Enemy::attack(Character* defender) {
  int chance = rand() % 2;
  if(chance == 1) {
    return Character::attack(defender);
  }
  return false;
}

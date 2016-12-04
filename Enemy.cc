#include "Enemy.h"
#include "CellType.cc"
#include "Game.h"
#include <stdlib.h>

Enemy::Enemy(bool isHostile): Character{0, 0, 0}, Cell{CellType::Empty}, isHostile{isHostile} {}

void Enemy::setIsHostile(bool hostility) {
  isHostile = hostility;
}
bool Enemy::getIsHostile() {
  return isHostile;
}
void Enemy::die() {
  reset();
  Game::getInstance()->getCurrentGrid()->removeEnemy(this);
}
bool Enemy::attack(Character* defender) {
  int chance = rand() % 2;
  if(chance == 1) {
    return Character::attack(defender);
  }
  return false;
}

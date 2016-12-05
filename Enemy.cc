#include "Enemy.h"
#include "CellType.cc"
#include "Game.h"
#include "Logger.h"
#include <stdlib.h>

Enemy::Enemy(bool isHostile): Character{0, 0, 0}, Cell{CellType::Empty}, isHostile{isHostile} {}

bool Enemy::getIsHostile() {
  return true;
}

void Enemy::die() {
  reset();
  Game::getInstance()->getCurrentGrid()->removeEnemy(this);
}

bool Enemy::willAttackSucceed(Character* defender) {
	return rand() % 2;
}

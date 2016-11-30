#include "Enemy.h"

Enemy::Enemy(int maxHp, int atk, int def, CellType cellType, bool isHostile = true): Character{maxHp, atk, def, cellType}, isHostile{isHostile} {}

void Enemy::setIsHostile(bool hostility) {
  isHostile = hostility;
}
bool Enemy::getIsHostile() {
  return isHostile;
}

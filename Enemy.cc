#include "Enemy.h"

Enemy::Enemy(int maxHp, int hp, int atk, int def): Character{maxHp, hp, atk, def} {}

void Enemy::setIsHostile(bool hostility) {
  isHostile = hostility;
}
bool Enemy::getIsHostile() {
  return isHostile;
}

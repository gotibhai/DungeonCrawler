#include "Dragon.h"

Dragon::Dragon(int maxHp, int hp, int atk, int def): Enemy{maxHp, hp, atk, def} {}

bool Dragon::move(Direction direction) {
  return false;
}

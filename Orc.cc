#include "Orc.h"
#include "Character.h"

Orc::Orc(int maxHp, int hp, int atk, int def): Enemy{maxHp, hp, atk, def} {}

bool Orc::attack(Character* character) {
  return false;
}

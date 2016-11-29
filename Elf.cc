#include "Elf.h"
#include "Character.h"

Elf::Elf(int maxHp, int hp, int atk, int def): Enemy{maxHp, hp, atk, def} {}

bool Elf::attack(Character* character) {
  return false;
}

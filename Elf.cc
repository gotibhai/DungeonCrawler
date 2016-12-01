#include "Elf.h"
#include "Character.h"

Elf::Elf(): Enemy{140,30,10}, Character{140, 30, 10}, Cell{CellType::Elf}{ }

bool Elf::attack(Character* defender) {
  int chance = rand() % 2;
  if(defender->getType() != CellType::Drow) {
    bool result1 =  Enemy::attack(defender);
    bool result2 =  Enemy::attack(defender);
    return result1 || result2;
  }
  return Enemy::attack(defender);
}

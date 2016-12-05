#include "Elf.h"
#include "Character.h"

Elf::Elf(): Character{140, 30, 10}, Cell{CellType::Elf}{ }

void Elf::attack(Character* defender) {
	Enemy::attack(defender);
	Enemy::attack(defender);
}

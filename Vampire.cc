#include "Vampire.h"
#include "Cell.h"
#include "Enemy.h"

Vampire::Vampire(): Race{125, 25, 25}, Cell{CellType::Vampire} {

}

void Vampire::attack(Character* defender) {
	Race::attack(defender);
  	if(defender->getType() != CellType::Dwarf) {
      this->setHp(this->getHp() + 5);
	} else {
  		this->setHp(this->getHp() - 5);
	}
}

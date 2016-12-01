#include "Vampire.h"
#include "Cell.h"
#include "Enemy.h"

Vampire::Vampire(): Race{125, 25, 25}, Cell{CellType::Vampire} {

}

bool Vampire::attack(Character* defender) {
  if(Race::attack(defender)) {
    if(defender->getType() != CellType::Dwarf) {
      this->setHp(this->getHp() + 5);
    } else {
      this->setHp(this->getHp() - 5);
      if(this->getHp() <= 0) {
        this->die();
      }
    }
    return true;
  }
  return false;
}

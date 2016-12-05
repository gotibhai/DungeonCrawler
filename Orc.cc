#include "Orc.h"
#include "Character.h"
#include <stdlib.h>
#include <math.h>


Orc::Orc(): Character{180, 30, 25}, Cell{CellType::Orc} {}

void Orc::attack(Character* defender) {
  int damage = ceil((100.0/(100.0+defender->getDef()))*this->getAtk());
  if(defender->getType() == CellType::Goblin) {
    damage = ceil(damage*1.5);
  }
  defender->setHp(defender->getHp()-damage);
  if(defender->getHp() <= 0) {
    defender->die();
  }
}

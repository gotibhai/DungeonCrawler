#include "Race.h"
#include <stdlib.h>

Race::Race(int hp, int atk, int def): Character{hp, atk, def} {}


int Race::getTotalGold() {
  return totalGold;
}
void Race::use(class Potion) {
 //hi
}
// void use(Gold);
int Race::getDef(){
  int length = potions.size();
  int totalDef = Character::getDef();
  for(int i = 0; i<length; i++) {
    totalDef += potions[i].getDef();
  }
  return totalDef;
}
int Race::getAtk(){
  int length = potions.size();
  int totalAtk = Character::getAtk();
  for(int i = 0; i<length; i++) {
    totalAtk += potions[i].getAtk();
  }
  return totalAtk;
}

void Race::resetPotions() {

}

bool Race::attack(Character* defender) {
  CellType defenderType = defender->getType();
  int chance = rand() % 2;
  if(defenderType == CellType::Halfling && chance == 0) {
    return false;
  }
  return Character::attack(defender);
}

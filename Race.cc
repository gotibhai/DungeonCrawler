#include "Race.h"

Race::Race(int hp, int atk, int def, CellType cellType): Character{hp, atk, def, cellType} {}


int Race::getTotalGold() {
  return totalGold;
}
void Race::use(class Potion) {
 //hi
}
// void use(Gold);
int Race::getDef(){
  int length = potions.size();
  int totalDef = 0;
  for(int i = 0; i<length; i++) {
    totalDef += potions[i].getDef();
  }
  return totalDef;
}
int Race::getAtk(){
  int length = potions.size();
  int totalAtk = 0;
  for(int i = 0; i<length; i++) {
    totalAtk += potions[i].getAtk();
  }
  return totalAtk;
}

void Race::resetPotions() {

}

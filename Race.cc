#include "Race.h"
#include "Game.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


Race::Race(int hp, int atk, int def): Character{hp, atk, def} {}

void Race::die() {
  Game::finishGame(false);
}

int Race::getTotalGold() {
  return totalGold;
}

void Race::use(class Potion potion) {
  cout << "Race::use" << endl;
  if (potion.getHp() != 0) {
    setHp(getHp() + potion.getHp());
  } else {
    potions.push_back(potion);
  }
}

void Race::use(GoldType goldType) {
  totalGold += (int) goldType;
  cout<<"incrementing "<<totalGold<<endl;
}
// void use(Gold);
int Race::getDef() {
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

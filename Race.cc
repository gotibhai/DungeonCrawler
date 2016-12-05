#include "Race.h"
#include "Game.h"
#include "Logger.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


Race::Race(int hp, int atk, int def): Character{hp, atk, def} {
  totalGold = 0;
}

void Race::die() {
  Game::finishGame(false);
}

int Race::getTotalGold() {
  return totalGold;
}

void Race::use(class Potion potion) {
  if (potion.getHp() != 0) {
    setHp(getHp() + potion.getHp());
  } else {
    potions.push_back(potion);
  }
}

void Race::use(GoldType goldType) {
  totalGold += (int) goldType;
}

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
  int length = potions.size();
 for(int i = 0; i<length; i++) {
    if(potions[i].getPotionType() != PotionType::RH || potions[i].getPotionType() != PotionType::PH){
       potions.erase(potions.begin() + i);
    }
  }
}

bool Race::willAttackSucceed(Character* defender) {
  if(defender->getType() == CellType::Halfling && rand() % 2 == 0) {
      return false;
  }
  return true;
}

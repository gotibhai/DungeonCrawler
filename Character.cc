#include "Character.h"
// #include "Direction.cc"
#include "CellType.cc"
#include "math.h"
#include "Race.h"
#include "Logger.h"
#include "Game.h"
#include "Merchant.h"
#include <string>

using namespace std;

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}, Cell{CellType::Empty} { }

void Character::attack(Character* defender) {
  if (this->willAttackSucceed(defender)) {
    int damage = ceil((100.0/(100.0+defender->getDef()))*(getAtk()));
    defender->setHp(defender->getHp()-damage);

    if (dynamic_cast<class Merchant*>(defender)) {
        dynamic_cast<class Merchant*>(defender)->setIsHostile(true);
    }

    Logger::getInstance()->attack(this, defender, damage);
  } else {
    Logger::getInstance()->missAttack(this, defender);
  }
}


void Character::winBattle() {

}

int Character::getHp() {
  return hp;
}
int Character::getAtk() {
  return atk;
}
int Character::getDef() {
  return def;
}
void Character::setHp(int newHp) {
  hp = newHp;

  if(this->getType() == CellType::Vampire){
    hp = newHp;
  } else if(hp >= maxHP){
    hp = maxHP;
  }

  if (hp <= 0) {
    die();
  }
}


bool Character::willAttackSucceed(Character*) {
  return true;
}

void Character::die() {

}

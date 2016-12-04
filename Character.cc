#include "Character.h"
// #include "Direction.cc"
#include "CellType.cc"
#include "math.h"
#include "Race.h"
#include "Logger.h"
#include <string>

using namespace std;

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}, Cell{CellType::Empty} { }

bool Character::attack(Character* defender) {
  int damage = ceil((100.0/(100.0+defender->getDef()))*(getAtk()));
  defender->setHp(defender->getHp()-damage);

  Logger::getInstance()->attack(this, defender, damage);
  
  return true;
}

void Character::die() {
  reset();
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

  if (hp <= 0) {
    die();
  }
}

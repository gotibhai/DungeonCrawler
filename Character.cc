#include "Character.h"
// #include "Direction.cc"
#include "CellType.cc"
#include <math.h>

Character::Character(int hp, int atk, int def): hp{hp}, atk{atk}, def{def}, Cell{CellType::Empty} { }

bool Character::move(Direction) {
  return false;
}

bool Character::attack(Character* defender) {
  int damage = ceil((100/(100+defender->getDef()))*this->atk);
  defender->setHp(defender->getHp()-damage);
  if(defender->getHp() <= 0) {
    defender->die();
  }
  return true;
}

void Character::die() {

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
}

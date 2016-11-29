#include "Character.h"

Character:Character(int maxHp, int hp, int atk, int def) {
  this->maxHp = maxHp;
  this->hp = hp;
  this->atk = atk;
  this->def = def;
}

bool Character::move(Direction) {
  return false
}
bool Character::attack(Character*) {
  return false
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

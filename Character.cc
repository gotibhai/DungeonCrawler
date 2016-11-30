#include "Character.h"
// #include "Direction.cc"
// #include "CellType.cc"

Character::Character(int hp, int atk, int def, CellType cellType): Cell{cellType}, hp{hp}, atk{atk}, def{def}{

}

bool Character::move(Direction) {
  return false;
}
bool Character::attack(Character*) {
  return false;
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

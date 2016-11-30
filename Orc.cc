#include "Orc.h"
#include "Character.h"

Orc::Orc(): Enemy{180, 30, 25} {}

bool Orc::attack(Character* character) {
  return false;
}

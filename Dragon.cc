#include "Dragon.h"

Dragon::Dragon(): Enemy{150,150,20}, Character{150, 150, 20}, Cell{CellType::Dragon} {}

bool Dragon::move(Direction direction) {
  return false;
}

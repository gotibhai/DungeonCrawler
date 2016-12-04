#include "Dragon.h"

Dragon::Dragon(): Character{150, 150, 20}, Cell{CellType::Dragon} {}

Dragon::~Dragon() {
  delete gold;
}

// bool Dragon::move(Direction direction) {
//   return false;
// }

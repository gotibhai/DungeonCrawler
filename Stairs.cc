#include "Stairs.h"
#include "Game.h"
#include "CellType.cc"

class Stairs: public ActionItem {
  public:
    Stairs::Stairs() ActionItem{CellType::Stairs}{};
    void use() {
    	Game.getCurrentGame().nextFloor();
    };
};


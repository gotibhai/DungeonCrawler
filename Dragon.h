#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "Enemy.h"
#include "Gold.h"
#include "Cell.h"

class Dragon: public Enemy {
private:
  class Gold *gold;
public:
  Dragon(class Gold*);
  void die() override;
  ~Dragon();

  // bool move(Direction) override;
};

#endif

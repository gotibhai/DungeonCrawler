#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "Enemy.h"
#include "Gold.h"

class Dragon: public Enemy {
private:
  Gold *gold;
public:
  Dragon(int, int, int, int);
  bool move(Direction) override;
};

#endif

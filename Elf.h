#ifndef __ELF_H__
#define __ELF_H__
#include "Enemy.h"
#include "Character.h"

class Elf: public Enemy {
public:
  Elf();
  void attack(Character*) override;
};

#endif

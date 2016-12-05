#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "Enemy.h"
#include "Gold.h"

class Merchant: public Enemy, public Gold {
private:
	static bool isHostile;
public:
  Merchant();
  void die();
  bool getIsHostile() override;
  void setIsHostile(bool);
};

#endif

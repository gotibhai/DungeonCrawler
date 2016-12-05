#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "Enemy.h"
#include "Gold.h"

class Merchant: public Enemy, public Gold {
public:
  Merchant();
  void die();
};

#endif

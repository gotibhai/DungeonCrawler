#ifndef __GOLD_H__
#define __GOLD_H__

#include "ActionItem.h"
#include "GoldType.cc"

class Gold: public ActionItem {
private:
  GoldType type;
  bool isCollectible;
public:
  bool use() override;
  void setIsCollectible(bool);
};

#endif

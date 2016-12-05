#include "Merchant.h"
#include "Gold.h"
#include "GoldType.cc"
#include "ActionItem.h"

Merchant::Merchant(): Enemy{false}, Character{30,70,5}, Cell{CellType::Merchant}, Gold{GoldType::MerchantGold}{}

void Merchant::die() {
	Gold *gold = new Gold(GoldType::MerchantGold);
	gold->setCoords(getRow(), getCol());
	setCellCovered(gold);
	Enemy::die();
}

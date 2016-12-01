#include "Merchant.h"
#include "Gold.h"
#include "ActionItem.h"

Merchant::Merchant(): Enemy{30,70,5,false}, Character{30, 70, 5}, Cell{CellType::Merchant}, Gold{GoldType::MerchantGold}{}

void Merchant::reset() {

}

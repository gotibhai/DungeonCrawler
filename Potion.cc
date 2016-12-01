#include "Potion.h"

Potion::Potion(PotionType p){
	potionType = p;
	value = p;
}

int Potion::getHp(){
	if(this->potionType == PotionType::RH || this->potionType == PotionType::PH){
		return this->potionType;
	} else {
		return 0;
	}
}

int Potion::getDef() {
	if(this->potionType == PotionType::BD || this->potionType == PotionType::WD){
		return this->potionType;
	} else {
		return 0;
	}
}

int Potion::getAtk() {
	if(this->potionType == PotionType::BA || this->potionType == PotionType::WA){
		return this->potionType;
	} else {
		return 0;
	}
}

void Potion::setValue(int val) {
	this->value = val;
}

int Potion::getValue() {
	return this->value;
}

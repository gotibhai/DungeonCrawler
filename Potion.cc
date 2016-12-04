#include "Potion.h"
#include <iostream>

Potion::Potion(PotionType p, int val){
	potionType = p;
	value = val;
}

int Potion::getHp(){
	if(this->potionType == PotionType::RH || this->potionType == PotionType::PH){
		return this->value;
	} else {
		return 0;
	}
}

int Potion::getDef() {
	if(this->potionType == PotionType::BD || this->potionType == PotionType::WD){
		return this->value;
	} else {
		return 0;
	}
}

int Potion::getAtk() {
	if(this->potionType == PotionType::BA || this->potionType == PotionType::WA){
		return this->value;
	} else {
		return 0;
	}
}

PotionType Potion::getPotionType(){
	return potionType;
}

void Potion::setValue(int val) {
	this->value = val;
}

int Potion::getValue() {
	return this->value;
}

#include "Dragon.h"

Dragon::Dragon(class Gold* g): Character{150, 150, 20}, Cell{CellType::Dragon} {gold = g;}


void Dragon::die(){
	gold->setIsCollectible(true);
}

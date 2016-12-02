#include "CellFactory.h"
#include "PotionCell.h"
#include "ActionItem.h"
#include "Gold.h"
#include "Human.h"
#include "Halfling.h"
#include "Dwarf.h"
#include "Orc.h"
#include "Elf.h"
#include "Merchant.h"
#include "Dragon.h"
#include "CellType.cc"
#include "Game.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Cell* CellFactory::getCell(char symbol){
	Cell *newcell = nullptr;
	if(symbol == '-'){
		newcell = new Cell(CellType::BorderHorizontal);
	} else if (symbol == '|'){
		newcell = new Cell(CellType::BorderVertical);
	} else if (symbol == '.'){
		newcell = new Cell(CellType::Ground);
	} else if (symbol == ' '){
		newcell = new Cell(CellType::Empty);
	} else if (symbol == '+'){
		newcell = new Cell(CellType::BridgeEnter);
	} else if (symbol == '#'){
		newcell = new Cell(CellType::Bridge);
	} else if(symbol  == 'H'){
		newcell = new class Human();
	} else if(symbol  == 'W'){
		newcell = new class Dwarf();
	} else if(symbol  == 'E'){
		newcell = new class Elf();
	} else if(symbol == 'O'){
		newcell = new class Orc();
	} else if(symbol  == 'L'){
		newcell = new class Halfling();
	} else if(symbol == 'M'){
		newcell = new class Merchant();
	} else if(symbol == 'D'){
		newcell = new class Dragon();
	}
	return newcell;
}

Cell* CellFactory::getGoldCell(int characters){
	Cell *newcell;
	if(characters == 6){
		newcell = new class Gold(GoldType::NormalGold);
	} else if (characters == 7){
		newcell = new class Gold(GoldType::SmallGold);
	} else if(characters == 8){
		newcell = new class Gold(GoldType::MerchantGold);
	} else if(characters == 9){
		newcell = new class Gold(GoldType::DragonGold);
	}

	return newcell;
}


std::vector<Cell *> CellFactory::getRandomGoldCell(){
	std::vector<Cell*> my_gold_vector;
		for(int i = 0; i < 10; i++){
			int random_number =  rand() % 8;
			Cell *newcell;
			if(random_number >= 0 && random_number < 5){
				newcell = new class Gold(GoldType::NormalGold);
			} else if (random_number == 5){
				newcell = new class Gold(GoldType::SmallGold);
			} else if (random_number > 5 && random_number < 8){
				newcell = new class Gold(GoldType::DragonGold);
			}
			my_gold_vector.push_back(newcell);
		}
		return my_gold_vector;
}



Cell* CellFactory::getPotionCell(int characters){
	Cell *newcell;
	class Potion *mypotion;
	if(characters == 0){
		mypotion = new class Potion(PotionType::RH);
	} else if(characters == 1){
		mypotion = new class Potion(PotionType::BA);
	} else if(characters == 2){
		mypotion = new class Potion(PotionType::BD);
	} else if(characters == 3){
		mypotion = new class Potion(PotionType::PH);
	} else if (characters == 4){
		mypotion = new class Potion(PotionType::WA);
	} else {
		mypotion = new class Potion(PotionType::WD);
	}
	newcell = new class PotionCell(mypotion);
	return newcell;
} 

std::vector<Cell *> CellFactory::generateRandPotions(){
		std::vector<Cell*> my_potion_vector;
		class Potion *mypotion;

		for(int i = 0; i < 10; i++){
			int random_number = rand() % 6;
			Cell *newcell;
			mypotion = new class Potion((PotionType) random_number);
			newcell = new class PotionCell(mypotion);
			my_potion_vector.push_back(newcell);
		}

		return my_potion_vector;
}

std::vector<Enemy *> CellFactory::generateEnemies(){
	std::vector<Enemy*> my_cell_vector;
	for(int i = 0; i < 20; i++){
		int random_number =  rand() % 18;
		Enemy *mycell;
		if(random_number >= 0 && random_number < 4){
			mycell = new class Human();
		} else if (random_number > 4 && random_number < 7){
			mycell = new class Dwarf();
		} else if (random_number > 7 && random_number < 12){
			mycell = new class Halfling();
		} else if (random_number > 12 && random_number < 14){
			mycell = new class Elf();
		} else if (random_number > 14 && random_number < 16){
			mycell = new class Orc();
		} else if (random_number > 16 && random_number < 18){
			mycell = new class Merchant();
		}
		my_cell_vector.push_back(mycell);
	}
	return my_cell_vector;
}

void CellFactory::place(Cell* cell) {
	int chamberNum = rand() % CellFactory::TOTAL_CHAMBERS;
	
	std::vector<Cell*> *chamber = &chambers[chamberNum];
		
	while(true) {
		int pos = rand() % (chamber->size());
		cout << "pos " << pos;

		if(chamber->at(pos)->getType() == CellType::Ground){
			cell->setCoords(chamber->at(pos)->getRow(), chamber->at(pos)->getCol());
			grid->setCell(cell);
			chamber->at(pos) = cell;
			return;
		}
	}
}

Grid* CellFactory::GenerateGridFromFile(std::string filename , Race* player){
	grid = new Grid();
	if(filename == Game::DEFAULT_FLOOR_FILE){
		std::ifstream file{filename};
		std::string str;
		char chars;
		int row = 0;
		int col = 0;
		for (int i = 0; i < CellFactory::TOTAL_CHAMBERS; i++) {
			chambers.push_back(vector<Cell*>());
		}
		cout << "works1 \n";
		// std::vector<Cell*> Chamber1;
		// std::vector<Cell*> Chamber2;
		// std::vector<Cell*> Chamber3;
		// std::vector<Cell*> Chamber4;
		// std::vector<Cell*> Chamber5;
		std::vector<Enemy*> enemy_vector = generateEnemies();
		std::vector<Cell*> potion_vector = generateRandPotions();
		std::vector<Cell*> gold_vector = getRandomGoldCell();

		grid->setEnemies(enemy_vector);

		while(std::getline(file,str)){		
			Cell *cell;
			int len = str.length();
			col = 0;
			for(int k=0; k < len; k++){
				cell = getCell(str[k]);
				cell->setCoords(row,col);
				grid->setCell(cell);

				if (str[k] =='.') {
					if(row >= 3 && row <=6 && col>=3 && col <= 28 ){
						chambers[0].push_back(cell);
					} else if (((row >= 3 && row <=6 && col>=39 && col <62) || (row == 5 && col >= 62 && col <70) 
						       || (row == 6 && col >=62 && col <73) || (row >= 7 && row <=12 && col>=61 && col < 76))) {
						chambers[1].push_back(cell);
					} else if (row >= 10 && row <=12 && col>=38 && col < 50){
						chambers[2].push_back(cell);
					} else if (row >= 15 && row <=21 && col>=4 && col <25){
						chambers[3].push_back(cell);
					} else {
						chambers[4].push_back(cell);
					}
				}
				col++;
			}
			row++;	
		}
		cout << "works2 \n";
		place(player);

		for (int i=0; i < gold_vector.size(); i++) {
			place(gold_vector[i]);
		}

		for (int i=0; i < potion_vector.size(); i++) {
			place(potion_vector[i]);
		}

		for (int i=0; i < enemy_vector.size(); i++) {
			place(enemy_vector[i]);
		}

		cout << "works3 \n";
		// int goldCount = 0;
		// int potionCount = 0;
		// for(int i = 0; i<25; i++) {

		// 	for(int j = 0; j<79; j++) {
		// 		if(mygrid->getCell(i, j)->getSymbol() == 'G') {
		// 			goldCount++;
		// 		}
		// 		else if(mygrid->getCell(i, j)->getSymbol() == 'P') {
		// 			potionCount++;
		// 		}
		// 	}
		// }
		// cout<<"Gold: "<< goldCount << endl;
		// cout<<"Potion: "<< potionCount << endl;

		
	} else {
		std::ifstream file{filename};
		std::string str;
		std::locale loc;
		int characters;
		char chars;
		int row = 0;
		int col = 0;
		while(std::getline(file,str)) {
			Cell *cell;
			std::istringstream iss{str};
			iss.exceptions(std::ios::failbit);
			while(iss>>chars){
				if(isdigit(chars,loc)){
					int characters = chars - '0';
					if(characters <= 5){
						//Create a Potion
						cell = getPotionCell(characters);

					} else if (characters > 5 && characters <= 9){
						//Create a Gold potion
						cell = getGoldCell(characters);						
					}
				} else {
					cell = getCell(chars);
				}
				cell->setCoords(row,col);
				grid->setCell(cell);
				col++;
			}
			row++;
			std::cout<<str<<std::endl;
		}
	}
	return grid;
}

const int CellFactory::TOTAL_CHAMBERS = 5;






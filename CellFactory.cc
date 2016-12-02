#include "CellFactory.h"
#include "PotionCell.h"
#include "ActionItem.h"
#include "Gold.h"
#include "Human.h"
#include "Halfling.h"
#include "Dwarf.h"
#include "Orc.h"
#include "Elf.h"
#include "Stairs.h"
#include "Merchant.h"
#include "Dragon.h"
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
		return newcell;

	} else if (characters == 7){
		newcell = new class Gold(GoldType::SmallGold);
		return newcell;

	} else if(characters == 8){
		newcell = new class Gold(GoldType::MerchantGold);
		return newcell;

	} else if(characters == 9){
		newcell = new class Gold(GoldType::DragonGold);
		return newcell;
	}
}


std::vector<Cell *> CellFactory::getRandomGoldCell(){
	std::vector<Cell*> my_gold_vector;
		for(int i = 0; i < 10; i++){
			int random_number =  rand() % (8) + 1;
			Cell *newcell;
			if(random_number >= 1 && random_number <= 5){
				newcell = new class Gold(GoldType::NormalGold);
				my_gold_vector.push_back(newcell);
			} else if (random_number == 6){
				newcell = new class Gold(GoldType::SmallGold);
				my_gold_vector.push_back(newcell);
			} else if (random_number > 6 && random_number <= 8){
				newcell = new class Gold(GoldType::DragonGold);
				my_gold_vector.push_back(newcell);
				Cell *dragoncell = new class Dragon();
				my_gold_vector.push_back(dragoncell);
			}
		}
		return my_gold_vector;
}



Cell* CellFactory::getPotionCell(int characters){
	Cell *newcell;
	class Potion *mypotion;
	if(characters == 0){
		mypotion = new class Potion(PotionType::RH);
		newcell = new class PotionCell(mypotion);
		return newcell;
	} else if(characters == 1){
		mypotion = new class Potion(PotionType::BA);
		newcell = new class PotionCell(mypotion);
		return newcell;

	} else if(characters == 2){
		mypotion = new class Potion(PotionType::BD);
		newcell = new class PotionCell(mypotion);
		return newcell;

	} else if(characters == 3){
		mypotion = new class Potion(PotionType::PH);
		newcell = new class PotionCell(mypotion);
		return newcell;

	}else if (characters == 4){
		mypotion = new class Potion(PotionType::WA);
		newcell = new class PotionCell(mypotion);
		return newcell;

	} else {
		mypotion = new class Potion(PotionType::WD);
		newcell = new class PotionCell(mypotion);
		return newcell;
	}
} 

std::vector<Cell *> CellFactory::generateRandPotions(){
		std::vector<Cell*> my_potion_vector;
		class Potion *mypotion;
		for(int i = 0; i < 10; i++){
			int random_number =  rand() % (7 - 1) + 1;
			Cell *newcell;
			if(random_number == 1){
				mypotion = new class Potion(PotionType::RH);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			} else if (random_number == 2 ){
				mypotion = new class Potion(PotionType::BA);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			} else if (random_number == 3){
				mypotion = new class Potion(PotionType::BD);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			} else if (random_number == 4){
				mypotion = new class Potion(PotionType::PH);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			} else if (random_number == 5){
				mypotion = new class Potion(PotionType::WA);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			} else if (random_number == 6){
				mypotion = new class Potion(PotionType::WD);
				newcell = new class PotionCell(mypotion);
				my_potion_vector.push_back(newcell);
			}
		}

		return my_potion_vector;
}

std::vector<Enemy *> CellFactory::generateEnemies(){
	std::vector<Enemy*> my_cell_vector;
	for(int i = 0; i < 20; i++){
		int random_number =  rand() % (19 - 1) + 1;
		Enemy *mycell;
		if(random_number >= 1 && random_number <= 4){
			mycell = new class Human();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 4 && random_number <= 7){
			mycell = new class Dwarf();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 7 && random_number <=12){
			mycell = new class Halfling();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 12 && random_number <=14){
			mycell = new class Elf();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 14 && random_number <=16){
			mycell = new class Orc();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 16 && random_number <=18){
			mycell = new class Merchant();
			my_cell_vector.push_back(mycell);
		}
	}
	return my_cell_vector;
}

int remember_row;
int remember_col;

void placer(Grid* mygrid, std::vector<Cell*> &Chamber1, std::vector<Cell*> &Chamber2, std::vector<Cell*> &Chamber3, std::vector<Cell*> &Chamber4, std::vector<Cell*> &Chamber5, Cell* cell , bool Dragon = false) {
	if(Dragon){
		int const total_dir = 8;
		int row = remember_row;
		int col = remember_col;
		while (true){

			int rand_dir = rand() % (total_dir) + 1;
			Direction direction = (Direction)rand_dir;
			if (direction == Direction::NO || direction == Direction::NE || direction == Direction::NW) {
			row -= 1;
			}
			if (direction == Direction::SO || direction == Direction::SE || direction == Direction::SW) {
				row += 1;
			}
			if (direction == Direction::WE || direction == Direction::SW || direction == Direction::NW) {
				col -= 1;
			}
			if (direction == Direction::EA || direction == Direction::SE || direction == Direction::NE) {
				col += 1;
			}
			if(mygrid->getCell(row,col)->getSymbol() == '.'){
				remember_row = row;
				remember_col = col;
				cout<<remember_row<<" "<<remember_col<<endl;
				cell->setCoords(remember_row,remember_col);
				mygrid->setCell(cell);
				break;
			}
		}
	} else {

		int chamberNum = rand() % (6 - 1) + 1;
		while(true) {
			std::vector<Cell*> *chamber;
			if(chamberNum == 1) {
				chamber = &Chamber1;
			} else if (chamberNum == 2) {
				chamber = &Chamber2;
			} else if (chamberNum == 3) {
				chamber = &Chamber3;
			} else if (chamberNum == 4) {
				chamber = &Chamber4;
			} else if (chamberNum == 5) {
				chamber = &Chamber5;
			} 
			int temp =  rand() % (chamber->size());
			if(mygrid->getCell(chamber->at(temp)->getRow() ,chamber->at(temp)->getCol())->getSymbol() == '.'){
				remember_row = chamber->at(temp)->getRow();
				remember_col = chamber->at(temp)->getCol();
				cell->setCoords(remember_row ,remember_col);
				mygrid->setCell(cell);
				break;
			}
		}
	}
}

Grid* CellFactory::GenerateGridFromFile(std::string filename , Race* player){
	Grid *mygrid =  new Grid();
	if(filename == "df.txt"){
		std::ifstream file{filename};
		std::string str;
		char chars;
		int row = 0;
		int col = 0;
		std::vector<Cell*> Chamber1;
		std::vector<Cell*> Chamber2;
		std::vector<Cell*> Chamber3;
		std::vector<Cell*> Chamber4;
		std::vector<Cell*> Chamber5;
		std::vector<Enemy*> enemy_vector = generateEnemies();
		mygrid->setEnemies(enemy_vector);
		std::vector<Cell*> potion_vector = generateRandPotions();
		std::vector<Cell*> gold_vector = getRandomGoldCell();

		while(std::getline(file,str)){		
			Cell *cell;
			int len = str.length();
			col = 0;
			for(int k=0; k < len; k++){
				cell = getCell(str[k]);
				cell->setCoords(row,col);
				mygrid->setCell(cell);
				if (str[k] =='.') {
					if(row >= 3 && row <=6 && col>=3 && col <= 28 ){
						Chamber1.push_back(cell);
					} else if (((row >= 3 && row <=6 && col>=39 && col <62) || (row == 5 && col >= 62 && col <70) 
						       || (row == 6 && col >=62 && col <73) || (row >= 7 && row <=12 && col>=61 && col < 76))) {
						Chamber2.push_back(cell);
					} else if (row >= 10 && row <=12 && col>=38 && col < 50){
						Chamber3.push_back(cell);
					} else if (row >= 15 && row <=21 && col>=4 && col <25){
						Chamber4.push_back(cell);
					} else {
						Chamber5.push_back(cell);
					}
				}
				col++;
			}
			row++;	
		}
		placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, player);

		Cell *newcell = new class Stairs();

		placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, newcell);

		int glength = gold_vector.size();

		for (int i=0; i < glength-1; i++) {
			if((char)gold_vector[i+1]->getType() == 'D' && i < glength-1){
				placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, gold_vector[i]);
				placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, gold_vector[i+1], true);
			}
			placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, gold_vector[i]);
		}

		int plength = potion_vector.size();

		for (int i=0; i < plength; i++) {
			placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, potion_vector[i] );
		}

		int length = enemy_vector.size();

		for (int i=0; i < length; i++) {
			placer(mygrid, Chamber1, Chamber2, Chamber3, Chamber4, Chamber5, enemy_vector[i] );
		}


		int goldCount = 0;
		int potionCount = 0;
		for(int i = 0; i<25; i++) {

			for(int j = 0; j<79; j++) {
				if(mygrid->getCell(i, j)->getSymbol() == 'G') {
					goldCount++;
				}
				else if(mygrid->getCell(i, j)->getSymbol() == 'P') {
					potionCount++;
				}
			}
		}
		// cout<<"Gold: "<< goldCount << endl;
		// cout<<"Potion: "<< potionCount << endl;

		return mygrid;
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
				mygrid->setCell(cell);
				col++;
			}
			row++;
			std::cout<<str<<std::endl;
		}
	}
}





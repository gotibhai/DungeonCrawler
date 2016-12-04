#include "CellFactory.h"
#include "PotionCell.h"
#include "ActionItem.h"
#include "Gold.h"
#include "Human.h"
#include "Halfling.h"
#include "Dwarf.h"
#include "Orc.h"
#include "Elf.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Stairs.h"
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
	} else if (symbol == '\\'){
		newcell = new class Stairs();
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
	}
	return newcell;
}

Cell* CellFactory::getGoldCell(int characters){
	Cell *newcell = nullptr;
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
		mypotion = new class Potion(PotionType::RH , 10);
	} else if(characters == 1){
		mypotion = new class Potion(PotionType::BA , 5);
	} else if(characters == 2){
		mypotion = new class Potion(PotionType::BD, 5);
	} else if(characters == 3){
		mypotion = new class Potion(PotionType::PH , -10);
	} else if (characters == 4){
		mypotion = new class Potion(PotionType::WA , -5);
	} else {
		mypotion = new class Potion(PotionType::WD , -5);
	}
	newcell = new class PotionCell(*mypotion);
	return newcell;
}

std::vector<Cell *> CellFactory::generateRandPotions(){
		std::vector<Cell*> my_potion_vector;
		class Potion *mypotion;

		for(int i = 0; i < 10; i++){
			int random_number = rand() % 6;
			Cell *newcell = newcell = getPotionCell(random_number);
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
		} else if (random_number >= 4 && random_number < 7){
			mycell = new class Dwarf();
		} else if (random_number >= 7 && random_number < 12){
			mycell = new class Halfling();
		} else if (random_number >= 12 && random_number < 14){
			mycell = new class Elf();
		} else if (random_number >= 14 && random_number < 16){
			mycell = new class Orc();
		} else if (random_number >= 16 && random_number < 18){
			mycell = new class Merchant();
		}
		my_cell_vector.push_back(mycell);
	}
	return my_cell_vector;
}


Cell* CellFactory::DragonPlacer(Cell* newcell){
	while(true){
		Direction direction = (Direction) (rand() % Direction::TOTAL);
		Cell *mycell = grid->getCellByDirection(newcell,direction);
		if(mycell->getType() == CellType::Ground){
			newcell->setCoords(mycell->getRow(),mycell->getCol());
			//cout<<newcell->getSymbol()<<endl;
			grid->setCell(newcell);
			return newcell;
		}
	}

}



void CellFactory::place(Cell* cell) {
	int chamberNum = rand() % CellFactory::TOTAL_CHAMBERS;	
	std::vector<Cell*> *chamber = &chambers[chamberNum];

	while(true) {
		int pos = rand() % (chamber->size());

		if(chamber->at(pos)->getType() == CellType::Ground){
			int row = chamber->at(pos)->getRow();
			int col = chamber->at(pos)->getCol();
			cell->setCoords(row, col);
			grid->setCell(cell);
			chamber->at(pos) = cell;
			if(cell->getType() == (char) 'G'){
				GoldType temp = dynamic_cast<class Gold*> (cell)->getGoldType();
				if(temp == 6){
					//cout<<"DGOLD is at "<<row<<" "<<col<<endl;
					Cell* newcell = new class Dragon(dynamic_cast<class Gold*> (cell));
					newcell->setCoords(row,col);
					Cell* dcell = DragonPlacer(newcell);
					//cout<<dcell->getSymbol()<<endl;
					//cout<<"DCELL is at "<<dcell->getRow()<<" "<<dcell->getCol()<<endl;
					for(int i = 0; i < chamber->size();i++){
						if(dcell->getRow() == chamber->at(i)->getRow() && dcell->getRow() == chamber->at(i)->getCol()){
							chamber->at(i) = dcell;
						}
					}
				}
			}
			return;
		}
	}
}

Grid* CellFactory::GenerateGridFromFile(std::string filename , Race* player, int floor){
	
	grid = new Grid();
	std::vector<Enemy*> enemy_vector;
	if(filename == Game::DEFAULT_FLOOR_FILE){
		std::ifstream file{filename};
		std::string str;
		char chars;
		int row = 0;
		int col = 0;
		for (int i = 0; i < CellFactory::TOTAL_CHAMBERS; i++) {
			chambers.push_back(vector<Cell*>());
		}

		enemy_vector = generateEnemies();
		std::vector<Cell*> potion_vector = generateRandPotions();
		std::vector<Cell*> gold_vector = getRandomGoldCell();

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

		place(player);

		class Stairs* stairs = new class Stairs();

		place(stairs);

		for (int i=0; i < gold_vector.size(); i++) {
			place(gold_vector[i]);
		}


		for (int i=0; i < potion_vector.size(); i++) {
			place(potion_vector[i]);
		}


		for (int i=0; i < enemy_vector.size(); i++) {
			place(enemy_vector[i]);
		}

	} else {
		std::ifstream file{filename};
		std::string str;
		std::locale loc;
		std::vector<std::vector<char>> File_arr;
		int characters;
		int i = 0;
		int floor_start = (floor * 25);
		if(floor != 0)floor_start++;
		int floor_end = floor_start + 25;
		if(floor == 0)floor_end++;
		//cout<<"Floor Start :"<<floor_start<<" Floor End :"<<floor_end<<endl;
		while(std::getline(file,str) && (i >= floor_start) && (i < floor_end)) {
			std::vector<char> line;
			for(int p = 0; p < str.length(); p++){
				line.push_back(str[p]);
			}
			File_arr.push_back(line);
			i++;
		}
		Cell *cell = nullptr;
		for(int k = 0; k < 25; k++){
			for(int j = 0; j < 79; j++){
				if(File_arr[k][j] == 'D') continue;
				if(isdigit(File_arr[k][j],loc)){
					int characters = File_arr[k][j] - '0';
					//cout<<"characters = "<<characters<<endl;
					if(characters <= 5){
						//Create a Potion
						cell = getPotionCell(characters);
					} else if (characters > 5 && characters < 9 ){
						//Create a Gold potion
						cell = getGoldCell(characters);
					} else if (characters == 9){
						cell = getGoldCell(characters);
						for(int a = k-1; a <= k+1; a++){
							for(int b = j-1; b <= j+1; b++){
								if(File_arr[a][b] == 'D'){
									//cout<<"Dragon coords : row : "<<a<<" Col : "<<b<<endl;
									Cell* newcell = new class Dragon(dynamic_cast<class Gold*>(cell));
									newcell->setCoords(a,b);
									grid->setCell(newcell);	
								}
							}
						}
					}
				} else {
					if(File_arr[k][j] == '@'){
						cell = player;
					} else {
						cell = getCell(File_arr[k][j]);
						if(dynamic_cast<class Enemy*> (cell)){
						   	enemy_vector.push_back(dynamic_cast<class Enemy*> (cell));
						}
					}
				}
				// if(k == 3){
				// 	cout<<"Row : "<<k<<" "<<"Col : "<<j<<cell->getSymbol()<<endl;
				// }
				cell->setCoords(k,j);
				grid->setCell(cell);
				//cout<<"Symbol = "<<cell->getSymbol();
			}
	    }
	}
	grid->setEnemies(enemy_vector);
	return grid;
}
	

const int CellFactory::TOTAL_CHAMBERS = 5;

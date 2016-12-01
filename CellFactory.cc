#include "CellFactory.h"
#include "Potion.h"
#include "PotionCell.h"
#include "Gold.h"

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
		// newcell = new class Human();
	} else if(symbol  == 'W'){
		// newcell = new class Dwarf();
	} else if(symbol  == 'E'){
		//newcell = new class Elf();
		
	} else if(symbol == 'O'){
		//newcell = new class Orc();
		
	} else if(symbol  == 'L'){
		//newcell = new class Halfling();
		
	} else if(symbol == 'M'){
		//newcell = new class Merchant();
	} else if(symbol == 'D'){
		//newcell = new class Dragon();
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

std::vector<Cell *> CellFactory::generateEnemies(){
	std::vector<Cell*> my_cell_vector;
	for(int i = 0; i < 20; i++){
		int random_number =  rand() % (19 - 1) + 1;
		Cell *mycell;
		if(random_number >= 1 && random_number <= 4){
			// mycell = new class Human();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 4 && random_number <= 7){
			// mycell = new class Dwarf();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 7 && random_number <=12){
			//mycell = new class Halfling();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 12 && random_number <=14){
			//mycell = new class Elf();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 14 && random_number <=16){
			//mycell = new class Orc();
			my_cell_vector.push_back(mycell);
		} else if (random_number > 16 && random_number <=18){
			//mycell = new class Merchant();
			my_cell_vector.push_back(mycell);
		}
	}
	return my_cell_vector;
}


Grid* CellFactory::GenerateGridFromFile(std::string filename){
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
		std::vector<Cell*> enemy_vector = generateEnemies();

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
				if(row == 10 || row == 11 || row == 12)
					cout<<row<<" "<<col<<" "<<str[k]<<endl;
				col++;
			}
			row++;	
		}

		int length = enemy_vector.size();

		for (int i=0; i < length; i++) {
			int chamber_num =  rand() % (6 - 1) + 1;
			int temp;
			if (chamber_num == 1){
				temp =  rand() % (Chamber1.size());
				if(Chamber1[temp]->getSymbol() == '.'){
					enemy_vector[i]->setCoords(Chamber1[temp]->getRow() ,Chamber1[temp]->getCol());
					mygrid->setCell(enemy_vector[i]);
				} else {
					i--;
					continue;
				}
				
			} else if (chamber_num == 2){
				//cout<<"Chamber size = "<<Chamber2.size();
				temp =  rand() % (Chamber2.size());
				//cout<<"temp = "<<temp<<endl;
				if(Chamber2[temp]->getSymbol() == '.'){
					enemy_vector[i]->setCoords(Chamber2[temp]->getRow() ,Chamber2[temp]->getCol());
					mygrid->setCell(enemy_vector[i]);
				} else {
					i--;
					continue;
				}
			} else if (chamber_num == 3){
				//cout<<"Chamber size = "<<Chamber3.size();
				temp =  rand() % (Chamber3.size());
				//cout<<"temp = "<<temp<<endl;
				if(Chamber3[temp]->getSymbol() == '.'){
					enemy_vector[i]->setCoords(Chamber3[temp]->getRow() ,Chamber3[temp]->getCol());
					mygrid->setCell(enemy_vector[i]);
				} else {
					i--;
					continue;
				}
			} else if (chamber_num == 4){
				//cout<<"Chamber size = "<<Chamber4.size();
				temp =  rand() % (Chamber4.size());
				//cout<<"temp = "<<temp<<endl;
				if(Chamber4[temp]->getSymbol() == '.'){
					enemy_vector[i]->setCoords(Chamber4[temp]->getRow() ,Chamber4[temp]->getCol());
					mygrid->setCell(enemy_vector[i]);
			    } else {
					i--;
					continue;
				}
			} else if (chamber_num == 5){
				//cout<<"Chamber size = "<<Chamber5.size();
				temp =  rand() % (Chamber5.size());
				//cout<<"temp = "<<temp<<endl;
				if(Chamber5[temp]->getSymbol() == '.'){
					enemy_vector[i]->setCoords(Chamber5[temp]->getRow() ,Chamber5[temp]->getCol());
					mygrid->setCell(enemy_vector[i]);
			    } else {
					i--;
					continue;
				}
				
			}
		}
		cout<<"here now"<<endl;
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





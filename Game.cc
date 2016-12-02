#include <iostream>
#include <string>
#include "Game.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "CellFactory.h"
using namespace std;

Game::Game() {
}

Game* Game::getInstance(string fileName) {
  Game::instance->floorFile = fileName;

  return Game::instance;
}
void Game::start(char raceType){
  if(raceType == 's') {
      player = new class Shade();
  } else if(raceType == 'd') {
      player = new class Drow();
  } else if(raceType == 'v') {
      player = new class Vampire();
  } else if(raceType == 't') {
      player = new class Troll();
  } else if(raceType == 'g') {
      player = new class Goblin();
  }
  floorNum = 0;
  nextFloor();
}
void Game::nextFloor() {
  currentGrid = CellFactory().GenerateGridFromFile(DEFAULT_FLOOR_FILE , player);
  cout<<*currentGrid<<endl;
  floorNum++;
}
bool Game::attack(Direction direction) {
  Cell* cell;
  switch(direction) {
    case(Direction::NO):
      cell = currentGrid->getCell(player->getRow() -1, player->getCol());
      break;
    case(Direction::SO):
      cell = currentGrid->getCell(player->getRow() +1, player->getCol());
      break;
    case(Direction::EA):
      cell = currentGrid->getCell(player->getRow(), player->getCol() +1);
      break;
    case(Direction::WE):
      cell = currentGrid->getCell(player->getRow(), player->getCol() -1);
      break;
    case(Direction::NE):
      cell = currentGrid->getCell(player->getRow() -1, player->getCol() +1);
      break;
    case(Direction::NW):
      cell = currentGrid->getCell(player->getRow() -1, player->getCol() -1);
      break;
    case(Direction::SE):
      cell = currentGrid->getCell(player->getRow() +1, player->getCol() +1);
      break;
    case(Direction::SW):
      cell = currentGrid->getCell(player->getRow() +1, player->getCol() -1);
      break;
  }
  if(cell->getType() != CellType::Halfling && cell->getType() != CellType::Dwarf &&
     cell->getType() != CellType::Elf && cell->getType() != CellType::Orc &&
     cell->getType() != CellType::Human && cell->getType() != CellType::Merchant) {
    return false;
  }

  player->attack(dynamic_cast<class Character*>(cell));
  cout<<"DAMAGING: "<<dynamic_cast<class Character*>(cell)->getHp()<<endl;
  return true;
  // if(direction == Direction::NO) {
  //   Cell* cell = currentGrid->getCell(player->getRow() -1, player->getCol());
  // } else if (direction ==)
  // player->attack(dynamic_cast<class Character*>(currentGrid->getCell(player->getRow() -1, player->getCol())));
  // // return player->attack(character);
  // return false;
}


bool Game::move(Direction direction) {
  return currentGrid->move(player , direction);
}
void Game::usePotion(class Potion potion) {
  //player.use(potion);
}

Grid* Game::getCurrentGrid() {
  return currentGrid;
}

Race* Game::getPlayer() {
  return player;
}

void Game::restart() {

}
void Game::finish() {

}
void Game::freeze() {

}

string translateRace(CellType type) {
  switch (type)
   {
      case Shade: return "Shade";
      case Drow: return "Drow";
      case Vampire: return "Vampire";
      case Troll: return "Troll";
      case Goblin: return "Goblin";
      default: return "Race";
   }
}


std::ostream &operator<<(std::ostream &out , Game *g) {
   out<<*(g->getCurrentGrid());
   out<<"Race: " << translateRace(g->getPlayer()->getType())<<endl;
   out<<"HP: "<<g->getPlayer()->getHp()<<endl;
   out<<"Atk: "<<g->getPlayer()->getDef()<<endl;
   out<<"Def: "<<g->getPlayer()->getAtk()<<endl;
  return out;
}

const std::string Game::DEFAULT_FLOOR_FILE = "df.txt";
Game* Game::instance = new Game();

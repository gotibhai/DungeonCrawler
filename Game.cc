#include <iostream>
#include <string>
#include "Game.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Gold.h"
#include "CellFactory.h"
#include "Logger.h"
#include "GoldType.cc"
#include "PotionCell.h"
using namespace std;

Game::Game(): toRestart{false}, toQuit{false} {

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

  toRestart = false;
}
void Game::nextFloor() {
  currentGrid = CellFactory().GenerateGridFromFile(DEFAULT_FLOOR_FILE, player);
  player->setCellCovered(new Cell());
  cout<<*currentGrid<<endl;
  floorNum++;
}

void Game::startMove() {
  isMoved = false;
  Logger::getInstance()->reset();
}

void Game::action(Action action) {
  switch (action) {
    case Action::FREEZE:
      currentGrid->setIsFrozen(true);
      return;
      break;
    case Action::RESTART:
      toRestart = true;
      return;
      break;
    case Action::QUIT:
      toQuit = true;
      return;
      break;
    default:
      return;
  }
  this->isMoved = true;
}


void Game::action(Action action, Direction direction) {
  cout << "action1 " << (char) action << "\n";

  isMoved = currentGrid->action(action, player, direction);


  cout << "action2 " << action << "\n";
  cout << "isMoved " << isMoved << "\n";

  if (isMoved) {
    currentGrid->enemiesMove();
    cout << this;
  }
}

void Game::use(ActionItem* actionItem) {
  cout << "Game::use " << (char) actionItem->getType() << endl;
  if (actionItem->getType() == CellType::Stairs) {
    nextFloor();
  }
  if (actionItem->getType() == CellType::Potion) {
        cout << "Grid::usePotion use " << (char) actionItem->getType() << endl;
    player->use(dynamic_cast<class PotionCell*>(actionItem)->getPotion());
    actionItem->reset();
  }
  if (actionItem->getType() == CellType::Gold) {
     cout<<"Using Gold : "<<endl;
     player->use(dynamic_cast<class Gold*>(actionItem)->getGoldType());
     actionItem->reset();
  }  
}

bool Game::isRestart() {
  return toRestart;
}

Grid* Game::getCurrentGrid() {
  return currentGrid;
}

bool Game::isQuit() {
  return toQuit;
}

bool Game::isPlayerMoved() {
  return isMoved;
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
   out<<*(g->currentGrid);
   out<<"Race: " << translateRace(g->player->getType())<<endl;
   out<<"HP: "<<g->player->getHp()<<endl;
   out<<"Atk: "<<g->player->getDef()<<endl;
   out<<"Def: "<<g->player->getAtk()<<endl;
   out<<"Action: " << Logger::getInstance()->getAction() <<endl;
  return out;
}

const std::string Game::DEFAULT_FLOOR_FILE = "df.txt";
Game* Game::instance = new Game();

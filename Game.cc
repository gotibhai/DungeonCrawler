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
#include <iomanip>
using namespace std;

bool Game::toQuit = false;
bool Game::won = false;

Game::Game(): toRestart{false}{

}

Game::~Game() {
  cout << "Game's Destructor" << endl;
  delete currentGrid;
  cout << "Grid Destructed" << endl;
  currentGrid = nullptr;
  player = nullptr;
  // delete instance;
}

Game* Game::getInstance() {
  if(Game::instance->floorFile == "") {
    Game::instance->floorFile = Game::DEFAULT_FLOOR_FILE;
  }
  return Game::instance;
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
  // delete currentGrid;
  if(floorNum==5) {
    Game::finishGame(true);
  }
  currentGrid = CellFactory().GenerateGridFromFile(floorFile, player, floorNum);
  player->setCellCovered(new Cell());
  player->resetPotions();
  floorNum++;
}

void Game::startMove() {
  cout << this;
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

void Game::setQuit(bool q) {
  Game::toQuit = q;
}



void Game::action(Action action, Direction direction) {
  isMoved = currentGrid->action(action, player, direction);

  if (isMoved) {
    currentGrid->enemiesMove();
  }
}

void Game::use(ActionItem* actionItem) {
  if (actionItem->getType() == CellType::Stairs) {
    nextFloor();
    return;
  }

  Logger::getInstance()->pickUp(actionItem);
  if (actionItem->getType() == CellType::PotionC) {
    player->use(dynamic_cast<class PotionCell*>(actionItem)->getPotion());
    actionItem->reset();
  }
  if (actionItem->getType() == CellType::Gold) {
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

void Game::finishGame(bool hasWon) {
  toQuit = true;
  won = hasWon;
}

bool Game::isWon() {
  return won;
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
   out<<"Race: " << translateRace(g->player->getType())<< " Gold: " << g->player->getTotalGold();
   out<<setw(55)<<"Floor: "<<g->floorNum<<endl;
   out<<"HP: "<<g->player->getHp()<<endl;
   out<<"Atk: "<<g->player->getAtk()<<endl;
   out<<"Def: "<<g->player->getDef()<<endl;
   out<<"Action: " << Logger::getInstance()->getAction() <<endl;
  return out;
}

const std::string Game::DEFAULT_FLOOR_FILE = "df.txt";
Game* Game::instance = new Game();

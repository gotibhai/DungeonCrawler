#include <iostream>
#include <string>
#include "Game.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "CellType.cc"
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
  floorNum = 1;
}
void Game::nextFloor() {
  floorNum++;
}
void Game::attack(Direction direction) {
  //player.attack(direction);
}


void Game::move(Direction direction) {
  //player.move(direction);
}
void Game::usePotion(class Potion potion) {
  //player.use(potion);
}

Grid Game::getCurrentGrid() {
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


std::ostream &operator<<(std::ostream &out, const Game &g) {
  out << "HELLO MATEY";
  return out;
}

const std::string Game::DEFAULT_FLOOR_FILE = "default_floor.txt";
Game* Game::instance = new Game();

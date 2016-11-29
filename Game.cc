#include <iostream>
#include <string>
#include "Game.h"
#include "Race.h"

Game::Game() {

}
Game::~Game() {

}
void Game::init(std::string fileName) {
  defaultFloorFile = fileName;
}
Game Game::getCurrentGame() {
  return currentGame;
}
void Game::start(char raceType){
  // player = new Race(raceType);
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
void Game::usePotion(Potion potion) {
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


// std::ostream &operator<<(std::ostream &out) {
// 	// out << currentGrid;
// 	return out;
// };

#include <iostream>
#include <string>
#include "Logger.h"
#include "Game.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Gold.h"
#include "CellFactory.h"
#include "Stairs.h"
#include "GoldType.cc"
#include "PotionCell.h"
using namespace std;

string stringDirection(Direction type) {
      if (type == Direction::NO) return "North";
      else if (type ==  Direction::SO) return "South";
      else if (type ==  Direction::EA) return "East";
      else if (type ==  Direction::WE) return "West";
      else if (type ==  Direction::NE) return "North-East";
      else if (type ==  Direction::NW) return "North-West";
      else if (type ==  Direction::SE) return "South-East";
      else if (type ==  Direction::SW) return "South-West";
}


Logger::Logger(): action{""} {}

Logger* Logger::getInstance() {
  return Logger::instance;
}

void Logger::attack(Character* character1, Character* character2, int damage) {
  bool isPlayer = dynamic_cast<class Race*>(character1);
  if (isPlayer) {
    action << "PC";
  } else {
    action << character1->getSymbol();
  }
  action << " deals " << damage << " damage to ";
  if (isPlayer) {
    action << character2->getSymbol() << "(" << character2->getHp() << " HP). ";
  } else {
    action << "PC";
  }
  action << ".";
}

void Logger::move(Direction direction, std::vector<Cell*> objectsNearby) {
  action << "PC moves " << stringDirection(direction);

  if (objectsNearby.size() > 0) {
    action << " and sees ";
  }
  bool isFirst = true;
  for(Cell* cell: objectsNearby) {
    if (!isFirst) {
      action << ", ";
    }
    isFirst = false;

    if (dynamic_cast<class Potion*>(cell)) {
      action << "unknown ";
    }
    action << cell->getSymbol();
  }
  action << ". ";
}

void Logger::pickUp(ActionItem* item) {
  action << "PC picks up " << item->getSymbol();
  action << ". ";
}

void Logger::reset() {
  action.str(string());
  action.clear();
}

string Logger::getAction() {
  return action.str();
}

Logger* Logger::instance = new Logger();

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

string getPotionTypeStr(PotionType potionType) {
  switch (potionType) {
    case PotionType::RH:
      return "RH";
    case PotionType::BA:
      return "BA";
    case PotionType::BD:
      return "BD";
    case PotionType::PH:
      return "PH";
    case PotionType::WA:
      return "WA";
    case PotionType::WD:
      return "WD";
  }
}

string getSymbol(Character* character) {
  stringstream streamString;
  streamString << character->getSymbol();
  return dynamic_cast<class Race*>(character)? "PC": streamString.str();
}

Logger::Logger(): action{""} {}

Logger* Logger::getInstance() {
  return Logger::instance;
}

void Logger::attack(Character* character1, Character* character2, int damage) {
  action << getSymbol(character1);
  if (character2->getHp() > 0) {
    action << " deals " << damage << " damage to ";
    action << getSymbol(character2);
    if (dynamic_cast<class Enemy*>(character2)) {
      action << "(" << character2->getHp() << " HP)";
    }
  } else {
    action << " kills " << getSymbol(character2);
  }

  action << ". ";
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
  if (dynamic_cast<class PotionCell*>(item)) {
    action << " of type "<< getPotionTypeStr(dynamic_cast<class PotionCell*>(item)->getPotion().getPotionType());
  } else if (dynamic_cast<class Gold*>(item)) {
    action << " which gives " << dynamic_cast<class Gold*>(item)->getGoldType() << " gold points to the PC";
  }
  action << ". ";
}

void Logger::missAttack(Character* character1, Character* character2) {
  action << getSymbol(character1) << " misses attack on "<< getSymbol(character2)<<". ";
}

void Logger::reset() {
  action.str(string());
  action.clear();
}

string Logger::getAction() {
  return action.str();
}

Logger* Logger::instance = new Logger();

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Race.h"
#include "Action.cc"
// #include "Direction.cc"
#include "Potion.h"
#include "ActionItem.h"
#include "Character.h"
#include "Direction.cc"
#include "Cell.h"
#include "Race.h"

class Logger {
	private:
        static Logger* instance;
        std::stringstream action;

    public:
         Logger();
        ~Logger();

    static Logger* getInstance();

    void attack(Character*, Character*, int);
    void move(Direction direction, std::vector<Cell*>);
	void pickUp(ActionItem*m);
    void missAttack(Character*, Character*);
    void reset();
    std::string getAction();
};




#endif

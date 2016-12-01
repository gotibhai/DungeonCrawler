#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Race.h"
// #include "Direction.cc"
#include "Potion.h"

class Game {
	private:
        static Game* instance;
        std::vector<std::string> floorFileNames;
        int score;
        Grid currentGrid;
        Race* player;
        int floorNum;
        std::string displayAction;
        std::string floorFile;
    public:
        Game();
        ~Game();
        static const std::string DEFAULT_FLOOR_FILE;
		// void init(std::string);
    static Game* getInstance(std::string fileName = Game::DEFAULT_FLOOR_FILE);

    void start(char);
    void nextFloor();
    void attack(Direction);
    void move(Direction);
    void usePotion(class Potion);
    Grid getCurrentGrid();
    Race* getPlayer();
    void restart();
    void finish();
    void freeze();

  friend std::ostream &operator<<(std::ostream &out, const Game &g);
};




#endif

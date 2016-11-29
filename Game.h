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
    static Game currentGame;
    std::vector<std::string> floorFileNames;
	  int score;
    Grid currentGrid;
    Race* player;
    int floorNum;
    std::string displayAction;
	public:
		Game();
    ~Game();
    static std::string defaultFloorFile;
		void init(std::string);
    static Game getCurrentGame();
    void start(char);
    void nextFloor();
    void attack(Direction);
    void move(Direction);
    void usePotion(Potion);
    Grid getCurrentGrid();
    Race* getPlayer();
    void restart();
    void finish();
    void freeze();

    //std::ostream &operator<<(std::ostream &out);
};


#endif

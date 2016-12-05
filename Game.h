#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Race.h"
#include "Action.cc"
// #include "Direction.cc"
#include "Potion.h"
#include "ActionItem.h"

class Game {
	private:
        static Game* instance;
        std::vector<std::string> floorFileNames;
        Grid* currentGrid;
        Race* player;
        int floorNum;
        std::string floorFile;

        bool toRestart;
        static bool toQuit;
        bool isMoved;
		static bool won;
        void nextFloor();
    public:
        Game();
        ~Game();
        static const std::string DEFAULT_FLOOR_FILE;
				// void init(std::string);

			  static Game* getInstance(std::string fileName);
				static Game* getInstance();
				static void finishGame(bool);

			  void start(char);
			  void action(Action);
			  void action(Action, Direction);
			  void use(ActionItem* actionItem);
			  // Grid* getCurrentGrid();
			  // Race* getPlayer();
			  bool isRestart();
			  bool isQuit();
				bool isWon();
			  bool isPlayerMoved();
			  Grid* getCurrentGrid();
			  void startMove();
				void setQuit(bool);

  friend std::ostream &operator<<(std::ostream &out , Game *g);
};




#endif

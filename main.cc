#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Grid.h"
#include "Game.h"
#include "CellType.cc"
#include "Action.cc"
#include <stdlib.h>
#include <time.h>

using namespace std;

bool isDirection(string dir) {
  return dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "nw" || dir == "ne" || dir == "sw" || dir == "se";
}

Direction translateDirection(string type) {
      if (type ==  "no") return Direction::NO;
      else if (type ==  "so") return Direction::SO;
      else if (type ==  "ea") return Direction::EA;
      else if (type ==  "we") return Direction::WE;
      else if (type ==  "ne") return Direction::NE;
      else if (type ==  "nw") return Direction::NW;
      else if (type ==  "se") return Direction::SE;
      else if (type ==  "sw") return Direction::SW;
}

void printInvalidCommand() {
  cout << "Invalid command, please try again: ";
}

void printWelcome() {
  cout<<"Welcome to CC3K!"<<endl;
  cout<<"Please choose one of the following races:"<<endl;
  cout<<"[s]hade"<<endl;
  cout<<"[d]row"<<endl;
  cout<<"[v]ampire"<<endl;
  cout<<"[t]roll"<<endl;
  cout<<"[g]oblin"<<endl;
}

void printCommands() {
  cout << "Pick a direction: no, so, ea, we, nw, ne, sw, se" << endl;
  cout << "Optionally can do 'a <direction>' to attack or " << endl;
  cout << "'u <direction' to use potion or " << endl;
  cout << "Type 'r' to restart or 'q' to quit." <<endl;
}

void printError(Action action) {
  cout<<"Cannot " << (char) action << " there. Try again."<<endl;
}

int main (int argc, char* argv[]) {
  srand(time(0));
  cin.exceptions(ios::eofbit|ios::failbit);

  cout<<"Arg Count: "<< argc<<endl;
  Game* game;
  if(argc > 1) {
    game = Game::getInstance(argv[1]);
  } else {
    game = Game::getInstance();
  }
  while(!game->isQuit()) {
    if(argc > 1) {
      game = Game::getInstance(argv[1]);
    } else {
      game = Game::getInstance();
    }
    printWelcome();

    char race;
    cin >> race;

    game->start(race);
    // create the grid and shit here (maybe game.start will do that stuff)
    while(!game->isRestart() && !game->isQuit()) {
      printCommands();

      game->startMove();
      while(!game->isPlayerMoved() && !game->isRestart() && !game->isQuit()) {
        string action;
        cin >> action;

        Action actionType = Action::NONE;

        if (isDirection(action)) {
          actionType = Action::MOVE;
        }

        if (actionType != Action::MOVE) {
          if (action.length() > 1) {
            printInvalidCommand();
            continue;
          }
          actionType = (Action) (char) action.at(0);
        }
        switch(actionType) {
          case Action::ATTACK:
          case Action::USE_POTION:
          case Action::MOVE: {
            string direction;

            if (actionType == Action::MOVE) direction = action;
            else cin >> direction;

            game->action(actionType, translateDirection(direction));

            if (!game->isPlayerMoved() && isDirection(action)) {
              printError(actionType);
            }
            break;}
          case Action::FREEZE:
          case Action::RESTART:
          case Action::QUIT: {
            game->action(actionType);
            break;}
          default:
            printInvalidCommand();
        }
        if(game->isQuit()) {
          cout<<"Game is over."<<endl;
          if(game->isWon()) {
            cout<<"Congrats you won!"<<endl;
          } else {
            cout<<"Sorry, you lost."<<endl;
          }
          if(action!="q") {
            cout<<game;
            cout<<"========================================="<<endl;
            cout<<"Do you wish to q or r?"<<endl;
            string ans;
            cin >> ans;
            if(ans == "r") {
              game->setQuit(false);
              game->action(Action::RESTART);
            }
            // delete game;
          }
        }

      }

      // delete game
    }
  }
};

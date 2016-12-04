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
    cout<<"Arg[1]: "<< argv[1]<<endl;
    game = Game::getInstance(argv[1]);
  } else {
    game = Game::getInstance();
  }
  while(!game->isQuit()) {
  if(argc > 1) {
    cout<<"Arg[1]: "<< argv[1]<<endl;
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

            if (!game->isPlayerMoved()) {
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

      }

      // check if won
      // check if lost
      // check if new floor
      // do enemies turn otherwise
      // check if lost
      // if won or lost, prompt to play again
      // if not wanna play again destruct everything
      // TODO: print the grid wherever necessary
    }
  }
};

// if(action == "a") {
        //     string direction;
        //     cin >> direction;
        //     // attack enemy
        //     if(game->attack(translateDirection(direction))) {
        //       cout<<"SUCCESSFUL ATTACK"<<endl;
        //       break;
        //     } else {
        //       cout<<"Cannot attack there. Try again."<<endl;
        //     }
        // }
        // else if(action == "u") {
        //     string direction;
        //     cin >> direction;
        //     // use potion
        //     cout<<game;
        //     break; // only if able to use the potion
        // }
        // else if(action == "r") {
        //     restart = true;
        //     break;
        // }
        // else if(action == "q") {
        //     quit = true;
        //     break;
        // }
        // else if(isDirection(action)) { // for moving playercx

        //     if(game->move(translateDirection(action))) {
        //       cout<<game;
        //       break; // only if move successful
        //     } else {
        //       cout<< "Cannot move there. Try again." << endl;
        //     }
        // }
        // else {
        //     cout << "Invalid command, please try again: ";
        // }

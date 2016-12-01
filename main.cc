#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Grid.h"
#include "Game.h"
#include "CellType.cc"
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

int main () {
  srand(time(0));
  cin.exceptions(ios::eofbit|ios::failbit);
  Grid grid();

  bool restart = true;
  while(restart) {
    restart = false;
    cout<<"Welcome to CC3K!"<<endl;
    cout<<"Please choose one of the following races:"<<endl;
    cout<<"[s]hade"<<endl;
    cout<<"[d]row"<<endl;
    cout<<"[v]ampire"<<endl;
    cout<<"[t]roll"<<endl;
    cout<<"[g]oblin"<<endl;

    char race;
    cin >> race;

    Game* game = Game::getInstance();
    game->start(race);
    // create the grid and shit here (maybe game.start will do that stuff)
    bool quit = false;
    while(!(quit || restart)) {
      cout << "Pick a direction: no, so, ea, we, nw, ne, sw, se" << endl;
      cout << "Optionally can do 'a <direction>' to attack or " << endl;
      cout << "'u <direction' to use potion or " << endl;
      cout << "Type 'r' to restart or 'q' to quit." <<endl;
      while(true) {
        string action;
        cin >> action;
        if(action == "a") {
            string direction;
            cin >> direction;
            // attack enemy
            cout<<game;
            break; // only if the attack succeed
        }
        else if(action == "u") {
            string direction;
            cin >> direction;
            // use potion
            cout<<game;
            break; // only if able to use the potion
        }
        else if(action == "r") {
            restart = true;
            break;
        }
        else if(action == "q") {
            quit = true;
            break;
        }
        else if(isDirection(action)) { // for moving playercx

            if(game->move(translateDirection(action))) {
              cout<<game;
              break; // only if move successful
            } else {
              cout<< "Cannot move there. Try again." << endl;
            }
        }
        else {
            cout << "Invalid command, please try again: ";
        }
      }
      game->getCurrentGrid()->moveEnemies();
      cout<<game;
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

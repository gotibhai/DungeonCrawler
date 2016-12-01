#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

#include "Grid.h"
#include "Game.h"
#include "CellType.cc"
#include "CellFactory.h"

using namespace std;

bool isDirection(string dir) {
  return dir == "no" || dir == "so" || dir == "ea" || dir == "we" || dir == "nw" || dir == "ne" || dir == "sw" || dir == "se";
}

int main () {
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
    cin>>race;

    Game game = Game();
    game.start(race);
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
            break; // only if the attack succeed
        }
        else if(action == "u") {
            string direction;
            cin >> direction;
            // use potion
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
            // move
            break; // only if move successful
        }
        else {
            cout << "Invalid command, please try again: ";
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

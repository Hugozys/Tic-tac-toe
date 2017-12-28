#include "GameDemon.h"
#include <cstdlib>

int main(void){
  GameDemon GM;
  GM.welcome();
  GM.createMajorPlayer();
  GM.createSecondPlayer();
  GM.decideOrder();
  std::cout<<"Game Start!"<<std::endl;
  GM.playGame();
  while(true){
    GM.eraseSecond();
    std::cout<<"Do you want to play again(Y/N)?"<<std::endl;
    std::string input;
    getline(std::cin,input);
    while(input != "N" && input != "Y"){
      std::cout<<"Please enter N or Y"<<std::endl;
      getline(std::cin,input);
    }
    if(input == "N"){
      break;
    }
    else if(input == "Y"){
      GM.clearbd();
      GM.createSecondPlayer();
      GM.decideOrder();
      std::cout<<"Game Start!"<<std::endl;
      GM.playGame();
      continue;
    }
  }
  return(EXIT_SUCCESS);
}

#include "GameDemon.h"
#include <cstdlib>
#include <time.h>
int main(void){
  srand(time(NULL));
  GameDemon GM;
  GM.welcome();
  GM.createMajorPlayer();
  GM.createSecondPlayer();
  GM.decideOrder();
  std::cout<<"Game Start!"<<std::endl;
  GM.playGame();
  while(true){
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
      GM.eraseSecond();
      GM.clearbd();
      GM.clearOrder();
      GM.createSecondPlayer();
      GM.decideOrder();
      std::cout<<"Game Start!"<<std::endl;
      GM.playGame();
      continue;
    }
  }
  return(EXIT_SUCCESS);
}

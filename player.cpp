#include "player.h"

 void humanPlayer::AskMyName(){
  std::cout<<"What's your name?"<<std::endl;
  std::string line;
  getline(std::cin,line);
  name = line;
}
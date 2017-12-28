#include "player.h"

void humanPlayer::AskMyName(){
  std::cout<<"What's your name?"<<std::endl;
  std::string line;
  getline(std::cin,line);
  name = line;
}

void humanPlayer::NameSecondPlayer(){
  std::cout<<"\n\nWhat's the name of second player?"<<std::endl;
  std::string line;
  getline(std::cin, line);
  name = line;
}

void aiPlayer::AskMyName(){
  name = "AI";
}

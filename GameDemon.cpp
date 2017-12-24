#include "GameDemon.h"
void AsterickGenerator(int num){
  for(int i = 0; i< num; ++i){
    std::cout<<"*";
  }
  std::cout<<std::endl;
}
void GameDemon::welcome(){
  AsterickGenerator(70);
  std::cout<<"*Welcome to Tic-tac-toe, a simple game application.                  *"<<std::endl;
  std::cout<<"*                                                                    *\n";
  //AsterickGenerator(20);
  std::cout<<"*Tic-tac-toe (also known as noughts and crosses or Xs and Os)is      *"<<std::endl;
  std::cout<<"*a paper-and-pencil game for two players, X and O, who take turns    *"<<std::endl;
  std::cout<<"*marking the spaces in a 3×3 grid. The player who succeeds in        *"<<std::endl;  
  std::cout<<"*placing three of their marks in a horizontal, vertical, or diagonal *"<<std::endl;
  std::cout<<"*row wins the game.                                                  *"<<std::endl;
  AsterickGenerator(70);
}

void GameDemon::createMajorPlayer(){
  pyArray[0] = new humanPlayer();
  pyArray[0]->AskMyName();
}
void GameDemon::createSecondPlayer(){
  pyArray[1] = new humanPlayer();
}

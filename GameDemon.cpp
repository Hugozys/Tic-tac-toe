#include "GameDemon.h"
#include <sstream>
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
  std::cout<<"\n\nDo you want to play with human or computer ?(Enter H for human and C for computer):"<<std::endl;
  std::string line;
  getline(std::cin,line);
  while(line != "H" && line != "C"){
    std::cout<<"Enter H for human and C for computer:"<<std::endl;
    getline(std::cin,line);
  }
  if(line == "H"){
    pyArray[1] = new humanPlayer();
    pyArray[1]->NameSecondPlayer();
  }
  else{
    pyArray[1] = new aiPlayer();
  }
}

void GameDemon::eraseSecond(){
  delete pyArray[1];
}

void GameDemon::decideOrder(){
  std::cout<<"\n\nHi, "<< pyArray[0]->getName()<<". "<<"Since you are the first player, you can choose side first: "<<std::endl<<"(Enter O to move first and Enter X to move second)"<<std::endl;
  std::string line;
  getline(std::cin,line);
  while(line != "O" && line != "X"){
    std::cout<<"Enter O to move first or X to move second:"<<std::endl;
    getline(std::cin,line);
  }
  if(line == "O"){
    order.push(pyArray[0]);
    order.push(pyArray[1]);
    pyArray[0]->changeOrder("O");
    pyArray[1]->changeOrder("X");
  }
  else{
    order.push(pyArray[1]);
    order.push(pyArray[0]);
    pyArray[0]->changeOrder("X");
    pyArray[1]->changeOrder("O");
  }
}

void GameDemon::showBoard(){
  bd.printBoard();
}


void GameDemon::playGame(){
  showBoard();
  std::string ans;
  player * curr = NULL;
  while((ans = bd.whoWins()) == "NONE"){
    if(bd.checkIsFull()){
      std::cout<<"Game Over. Dual."<<std::endl;
      return;
    }
    else{
      curr = order.front();
      order.pop();
      order.push(curr);
      std::cout<< curr->getName()<<"'s turn:"<<std::endl;
      while(true){
	std::string input;
	getline(std::cin,input);
	if(!bd.isValid(input)){
	  std::cout<<"invalid coordinate, please reenter:\n";
	  continue;
	}
	std::stringstream ss;
	ss<<input;
	int row, column;
	ss>>row;
	ss>>column;
	if(bd.isOutRange(row,column)){
	  std::cout<<"The coordinate is out of range([0,2]),please reenter:\n";
	  continue;
	}
	if(bd.isOccupied(row,column)){
	  std::cout<<"This block has already been occupied, please reenter:\n";
	  continue;
	}
	bd.update(row,column,curr->getPawnType());
	showBoard();
	break;
      }
    }
  }
  std::cout<<"Game Over. "<<curr->getName()<<" wins!"<<std::endl;
  return;
}
  
void GameDemon::clearbd(){
  bd.clearBoard();
}
      
    

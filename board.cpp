#include <iostream>
#include "board.h"
void thirteenPound(){
  for(int i = 0 ; i < 13; ++i){
    std::cout<<"#";
  }
  std::cout<<std::endl;
}
char board:: showSymbol(int row, int column){
  char ans;
  switch(snapShot[row][column]){
  case 0:
    ans = ' ';
    break;
  case 1:
    ans = 'O';
    break;
  case -1:
    ans = 'X';
    break;
  }
  return ans;
}
  
void board::poundWithXO(int i){
  for(int j = 0; j < 3; ++j){
    std::cout<<"# "<< showSymbol(i,j)<< " ";
  }
  std::cout<<"#"<<std::endl;
}

void board::printBoard(){
  for(int i = 0; i < 3; ++ i){
    thirteenPound();
    poundWithXO(i);
  }
  thirteenPound();
}
bool board::checkWinnerOption(std::string whichWay,int toCheck){
  bool markContainer = true;
  if(whichWay != "majorDia" && whichWay !="minorDia"){
    for(int i = 0; i < 3; ++i){
      markContainer = true;
      for(int j = 0; j < 3; ++j){
	if(whichWay == "horizontal"){
	  if(snapShot[i][j] != toCheck){
	    markContainer = false;
	    break;
	  }
	}
	else{
	  if(snapShot[j][i] != toCheck){
	    markContainer = false;
	    break;
	  }
	}
      }
      if(markContainer){
	return true;
      }
    }
    return false;
  }
  else{ //diagonal
    for(int i = 0; i < 3; ++i){
      markContainer = true;
      if(whichWay == "majorDia"){
	if(snapShot[i][i] != toCheck){
	  markContainer = false;
	  break;
	}
      }
      else{
	if(snapShot[2-i][2-i] != toCheck){
	  markContainer = false;
	  break;
	}
      }
    }
    if(markContainer){
      return true;
    }
    return false;
  }
}
	  
	 
bool board::isWinner(int toCheck){
  if(checkWinnerOption("horizontal",toCheck) ||
     checkWinnerOption("vertical",toCheck)   ||
     checkWinnerOption("majorDia",toCheck)   ||
     checkWinnerOption("minorDia",toCheck)){
    return true;
  }
  else{
    return false;
  }
}
      

std::string board::whoWins(){
  if(isWinner(1)){
    return "O";
  }
  else if(isWinner(-1)){
    return "X";
  }
  else{
    return "NONE";
  }
}
    

bool board::checkIsFull(){ //This means dual
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      if ( snapShot[i][j] == 0){
	return false;
      }
    }
  }
  return true;
}

bool board::isValid(std::string line){
}

bool board::isOutRange(int row, int column){
  bool r = row >= 0 && row <= 2; //out of range, return false
  bool c = column>=0 && row <= 2;
  if( !r || !c){
    return true;
  }
  return false;
}

bool isOccupied(int row, int column){
  if(snapShot[row][column] != 0){
    return true;
  }
  else{
    return false;
  }
}

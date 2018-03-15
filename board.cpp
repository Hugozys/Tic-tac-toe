#include <iostream>
#include "board.h"
#include <climits>
#include <cstdio>
#include <sstream>
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
	if(snapShot[2-i][i] != toCheck){
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

bool isDigit(std::string line){
  std::string::const_iterator it = line.begin();
  while(it != line.end()){
      if(!(*it >= '0' && *it <= '9')){
	return false;
      }
      ++it;
    }
    return true;
}

bool board::isValid(std::string line){
  std::stringstream ss;
  ss<<line;
  std::string num1;
  std::string num2;
  ss>>num1;
  ss>>num2;
  if(num1.empty() || num2.empty()){
    return false;
  }
  else if( !isDigit(num1) || !isDigit(num2)){
    return false;
  }
  else{
    return true;
  }
}

bool board::isOutRange(int row, int column){
  bool r =  (row < 0 || row > 2); //out of range, return true
  bool c =  (column < 0 || column > 2);
  if( r || c){
    return true;
  }
  return false;
}

bool board::isOccupied(int row, int column){
  if(snapShot[row][column] != 0){
    return true;
  }
  else{
    return false;
  }
}

void board::update(int row, int column,const std::string & type){
  if(type == "O"){
    snapShot[row][column] = 1;
  }
  else{
    snapShot[row][column] = -1;
  }
}
void board::clearBoard(){
  for(int i = 0; i < 3; ++i){
    for(int j =0; j <3; ++j){
      snapShot[i][j] = 0;
    }
  }
}

void board::notEmpty(){
  is_empty = false;
}

bool board::isEmpty(){
  return is_empty;
}

board::board(board && rhs){
  snapShot = std::move(rhs.snapShot);
  is_empty = rhs.is_empty;
}

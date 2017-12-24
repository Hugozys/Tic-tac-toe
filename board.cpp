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

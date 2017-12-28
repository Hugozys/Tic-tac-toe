#include<iostream>
#include "board.h"
#include <cstdlib>

/*void print( board & subject){
 *  for(int i = 0 ; i < (int) subject.snapShot.size() ; ++i){
 *  for (int j = 0; j < (int) subject.snapShot[i].size(); ++j){
 *    std::cout<< subject.snapShot[i][j]<< " ";
 *  }
 *  std::cout<<std::endl;
 *}
 *std::cout<<std::endl;
 *}
*/
void board::changeHor(int t, int toChange){
  for(int i = 0; i < 3; ++i){
    snapShot[t][i] = toChange;
  }
}
void board::changeVer(int t, int toChange){
  for(int i = 0; i < 3; ++i){
    snapShot[i][t] = toChange;
  }
}
    
void board::changeSnapShot(int line){
  switch (line){
  case 10:
    changeHor(0,1);
    break;
  case 20:
    changeHor(1,1);
    break;
  case 30:
    changeHor(2,1);
    break;
  case 110:
    changeVer(0,1);
    break;
  case 120:
    changeHor(1,1);
    break;
  case 1301:
    changeHor(2,1);
    break;
  case -1:
    for(int i = 0; i< 3; ++i){
      snapShot[2-i][2-i] = 1;
    }
    break;
  case -2:
    for(int i = 0; i< 3; ++i){
      snapShot[i][i] = 1;
    }
    break;
  default:
    for(int i = 0; i< 3; ++i){
      snapShot[2-i][2-i] = 1;
    }
  }
}
int main(void){
  board bd_hor_1;
  board bd_hor_2;
  board bd_hor_3;
  board bd_ver_1;
  board bd_diaMa;
  board bd_diaMi;
  board bd_none;
  //print(aboard);
  bd_hor_1.changeSnapShot(10);
  bd_hor_2.changeSnapShot(20);
  bd_ver_1.changeSnapShot(110);
  bd_diaMa.changeSnapShot(-1);
  bd_diaMi.changeSnapShot(-2);
  std::cout<< bd_hor_1.checkWinnerOption("horizontal",1)<<std::endl;
  std::cout<< bd_hor_2.checkWinnerOption("horizontal",1)<<std::endl;
  std::cout<< bd_diaMa.checkWinnerOption("majorDia",1)<<std::endl;
  std::cout<< bd_diaMi.checkWinnerOption("minorDia",1)<<std::endl;
  bd_diaMi.printBoard();
  std::cout<< bd_none.checkWinnerOption("horizontal",1)<<std::endl;
  
  return(EXIT_SUCCESS);
}

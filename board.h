#ifndef _BOARD__H
#define _BOARD__H
#include<vector>
class board{
  std::vector<std::vector<int> > snapShot;
 public:
 board():snapShot(3,std::vector<int>(3,0)){}
  //friend void print (board & subject);
 void printBoard();
 char showSymbol(int row, int column);
 void poundWithXO(int i);
};
 

#endif

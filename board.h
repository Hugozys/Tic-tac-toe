#ifndef _BOARD__H
#define _BOARD__H
#include<vector>
#include <string>
class board{
  std::vector<std::vector<int> > snapShot;
  bool is_empty;
 public:
 board():snapShot(3,std::vector<int>(3,0)),is_empty(true){}
  board(const board & rhs) = default;
  board(board && rhs);
  //friend void print (board & subject);
 void printBoard();
 char showSymbol(int row, int column);
 void poundWithXO(int i);
 bool checkIsFull();
 bool checkWinnerOption(std::string whichWay,int toCheck);
 bool isWinner(int toCheck);
 std::string whoWins();
 //void changeSnapShot(int line);
 //void changeHor(int t, int toChange);
 //void changeVer(int t, int toChange);
 bool isOutRange(int row, int column);
 bool isOccupied(int row, int column);
 bool isEmpty();
 void notEmpty();
 bool isValid(std::string line);
 void update(int row, int column,const std::string & type);
 void clearBoard();
};
 

#endif

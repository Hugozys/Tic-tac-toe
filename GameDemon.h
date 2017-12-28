#ifndef _GameDemon__H
#define _GameDemon__H
#include "board.h"
#include "player.h"
#include <queue>
class GameDemon{
  board bd;
  player ** pyArray;
  queue<player *> order;
 public:
  GameDemon():bd(),pyArray(new player * [2]()){}
  void welcome();
  void createMajorPlayer();
  void createSecondPlayer();
  void decideOrder();
  void playGame();
  
  
  ~GameDemon(){
    delete pyArray[1];
    delete pyArray[0];
    delete [] pyArray;
  }
  void showBoard();
};
#endif

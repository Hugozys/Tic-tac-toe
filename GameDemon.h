#ifndef _GameDemon__H
#define _GameDemon__H
#include "board.h"
#include "player.h"
class GameDemon{
  board bd;
  player ** pyArray;
 public:
  GameDemon():bd(),pyArray(new player * [2]()){}
  void welcome();
  void createMajorPlayer();
  void createSecondPlayer();
  ~GameDemon(){
    delete pyArray[1];
    delete pyArray[0];
    delete [] pyArray;
  }
};
#endif

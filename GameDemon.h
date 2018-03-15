#ifndef _GameDemon__H
#define _GameDemon__H
#include "board.h"
#include "player.h"
#include <queue>
class GameDemon{
  board bd;
  player ** pyArray;
  std::queue<player *> order;
 public:
  GameDemon():bd(),pyArray(new player * [2]()){}
  void welcome();
  void createMajorPlayer();
  void createSecondPlayer();
  void decideOrder();
  void playGame();
  void eraseSecond();
  void clearbd();
  void human_turn(player * curr);
  void ai_turn(player * curr);
  void clearOrder();
  ~GameDemon(){
    delete pyArray[1];
    delete pyArray[0];
    delete [] pyArray;
  }
  void showBoard();
};
#endif

#ifndef _PLAYER__H
#define _PLAYER__H
#include<string>
#include<iostream>
#include "board.h"
#include <utility>
class player{
 protected:
  std::string name;
  std::string pawnType;
  
 public:
 player():name("AI"),pawnType(){}
  virtual void AskMyName() = 0;
  virtual ~player(){}
  virtual void NameSecondPlayer(){}
  virtual void changeOrder(std::string type){
    pawnType = type;
  }
  virtual std::string getName() const{
    return name;
  }
  
  virtual std::string getPawnType() const{
    return pawnType;
  }
  virtual std::pair<int,int> getBestMove(board & bd){return std::pair<int,int>();}
  virtual int getBestMoveHelper(board && bd, std::string type){return 0;}
};


class humanPlayer: public player{
public:
  virtual void AskMyName();
  void NameSecondPlayer();
  virtual ~humanPlayer(){};
};

class aiPlayer: public player{
 public:
  virtual void AskMyName();
  virtual ~aiPlayer(){}
  virtual std::pair<int,int> getBestMove(board & bd);
  virtual int getBestMoveHelper(board && bd, std::string type, int depth);
};

#endif

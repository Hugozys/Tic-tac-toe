#ifndef _PLAYER__H
#define _PLAYER__H
#include<string>
#include<iostream>
class player{
 protected:
  std::string name;
  std::string order;
  
 public:
  player():name(),order(){}
  virtual void AskMyName() = 0;
  virtual ~player(){}
};

class humanPlayer: public player{
public:
  virtual void AskMyName();
  virtual ~humanPlayer(){};
};
#endif

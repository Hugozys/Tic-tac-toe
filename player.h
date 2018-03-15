#ifndef _PLAYER__H
#define _PLAYER__H
#include<string>
#include<iostream>
class player{
 protected:
  std::string name;
  std::string pawnType;
  
 public:
 player():name(),pawnType(){}
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
};

class humanPlayer: public player{
public:
  virtual void AskMyName();
  void NameSecondPlayer();
  virtual ~humanPlayer(){};
};

class aiPlayer: public player{
 private:
  vector<
 public:
  virtual void AskMyName();
  virtual ~aiPlayer(){}
  
};

#endif

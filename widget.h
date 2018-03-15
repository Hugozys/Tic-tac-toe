#ifndef _WIDGET__H
#define _WIDGET__H
#include <utility>

class moveRecorder{
 private:
  int score;
  std::pair<int,int> position;
 public:
  moveRecorder(int sc,int r,int c);
  int getScore();
  std::pair<int,int> getPosition();
};

class compareMoveRecorder{
 public:
  bool operator ()(moveRecorder &lhs, moveRecorder &rhs);
};

#endif

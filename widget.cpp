#include "widget.h"

moveRecorder::moveRecorder(int sc, int r, int c):score(sc),position(r,c){}


int moveRecorder::getScore(){
  return score;
}

std::pair<int,int> moveRecorder::getPosition(){
  return position;
}

bool compareMoveRecorder::operator() (moveRecorder & lhs, moveRecorder & rhs){
  return lhs.getScore() < rhs.getScore();
}

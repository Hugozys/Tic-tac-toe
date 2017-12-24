#include "GameDemon.h"
#include <cstdlib>

int main(void){
  GameDemon GM;
  GM.welcome();
  GM.createMajorPlayer();
  GM.createSecondPlayer();
  //GM.decideOrder();
  return(EXIT_SUCCESS);
}

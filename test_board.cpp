#include<iostream>
#include "board.h"
#include <cstdlib>

/*void print( board & subject){
 *  for(int i = 0 ; i < (int) subject.snapShot.size() ; ++i){
 *  for (int j = 0; j < (int) subject.snapShot[i].size(); ++j){
 *    std::cout<< subject.snapShot[i][j]<< " ";
 *  }
 *  std::cout<<std::endl;
 *}
 *std::cout<<std::endl;
 *}
*/


int main(void){
  board aboard;
  //print(aboard);
  aboard.printBoard();
  return(EXIT_SUCCESS);
}

#include "player.h"
#include "widget.h"
#include <queue>
#include <exception>
void humanPlayer::AskMyName(){
  std::cout<<"What's your name?"<<std::endl;
  std::string line;
  getline(std::cin,line);
  name = line;
}

void humanPlayer::NameSecondPlayer(){
  std::cout<<"\n\nWhat's the name of second player?"<<std::endl;
  std::string line;
  getline(std::cin, line);
  name = line;
}

void aiPlayer::AskMyName(){
  name = "AI";
}


/**
 *You are going to write this method for aiPlayer class
 *This method will take a current snapshot of the board 
 *and figure out what the best move is for the AI to take 
 *in current round and return a vector containing the 
 *row and column where that best move belongs to.
 *You may assume that there is at least one pawn on the 
 *board. You may also assume that currenly the game is 
 *still incompleted (no tie/win/lose)
 **/

std::string accessNext(std::string type){
  if(type == "O"){
    return "X";
  }
  else{
    return "O";
  }
}

int find(std::vector<int> & result, std::string what){
  if(result.empty()){
    throw std::exception();
  }
  int ans = result[0];
  for(auto item: result){
    if(what == "min"){
      ans = std::min(ans, item);
    }
    else{
      ans = std::max(ans,item);
    }
  }
  return ans;
}
    
    

int aiPlayer::getBestMoveHelper(board && bd, std::string type, int depth){
  if(bd.whoWins() == "NONE"){ //no one wins
    if(bd.checkIsFull()){ //dual
      return 0;
    }
    else{ //not complete
      std::vector<int> result; //score list
      for (size_t i = 0; i < 3; ++ i){
	for(size_t j = 0; j < 3; ++j){
	  if(bd.isOccupied(i,j)){
	    continue;
	  }
	  else{
	    board temp = bd; 
	    temp.update(i,j,type); //someone plays this move ans;
	    int ans;
	    result.push_back(ans = getBestMoveHelper(std::move(temp),accessNext(type),depth + 1 ));
	    std::cout<<"DEPTH:"<<depth<<" I am " << type << "." << "If I put a move at ("<<i<<","<<j<<"). I will get the following point."<<ans<<std::endl;
	  }
	}
      }
      if(type == pawnType){ //AI plays this move
	return find(result,"max");
	//human plays the next move and will return a minimum score
	//I'm AI so I want to return a maximum score
      }
      else{
	return find(result,"min");
	      //AI plays the next move and will return a maximum score
	      //I'm human so I want to return a minimum score
      }
    }
  }
  else if(bd.whoWins() == pawnType){ //ai wins
    return 10;
  }
  else{ //human wins
    return -10;
  }
}
  
    



std::pair<int,int> aiPlayer::getBestMove(board & bd){
  std::priority_queue<moveRecorder,std::vector<moveRecorder>, compareMoveRecorder> cheatsheet;
  for (size_t i = 0; i < 3; ++ i){
    for(size_t j = 0; j < 3; ++j){
      if(bd.isOccupied(i,j)){
	continue;
      }
      else{
	board temp(bd);
	temp.update(i,j,pawnType);
	int score = getBestMoveHelper(std::move(temp),accessNext(pawnType), 0);
	std::cout<<"If I make a move at ("<<i<<", "<<j<<"). That will result in this point: "<<score<<std::endl;
	cheatsheet.push(moveRecorder(score,i,j));
      }
    }
  }
  moveRecorder ans = cheatsheet.top();
  std::cout<<ans.getScore()<<std::endl;
  return ans.getPosition();
}

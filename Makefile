.PHONY: clean depend
CXX = g++ -std=gnu++03 -Wall -Werror -pedantic -ggdb3
CXXO = g++ -std=gnu++03 -Wall -Werror -pedantic -ggdb3 -o $@
#SRCS = $(wildcard *.cpp)
#OBJS = $(patsubst %.cpp,%.o,$(SRCS))
all: Tic-tac-toe

testBoard: test_board.cpp board.h board.cpp
	$(CXX) -o $@ test_board.cpp board.cpp

Tic-tac-toe: board.o tic_tac_toe.o GameDemon.o player.o
	$(CXXO) board.o tic_tac_toe.o GameDemon.o player.o
%.o: %.cpp
	$(CXX) -c $<
clean:
	rm -f *.o *~ *# *.bak

depend:
	makedepend board.cpp GameDemon.cpp tic_tac_toe.cpp player.cpp
# DO NOT DELETE

board.o: board.h
GameDemon.o: GameDemon.h board.h player.h
tic_tac_toe.o: GameDemon.h board.h player.h
player.o: player.h

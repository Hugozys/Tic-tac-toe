.PHONY: clean
CXX = g++ -std=gnu++03 -Wall -Werror -pedantic -ggdb3

testBoard: test_board.cpp board.h board.cpp
	$(CXX) -o $@ test_board.cpp board.cpp


clean:
	rm -f *.o *~ *#

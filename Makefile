.PHONY: all tests clean

all: sudoku_solver

sudoku_solver: obj/main.o obj/grid.o obj/solver.o
	g++ -Wall -Wextra -g -o $@ $^ 

obj/main.o: main.cpp
	g++ -Wall -Wextra -g -c main.cpp -o $@
obj/grid.o: grid.cpp grid.hpp
	g++ -Wall -Wextra -g -c grid.cpp -o $@
obj/solver.o: solver.cpp solver.hpp
	g++ -Wall -Wextra -g -c solver.cpp -o $@

tests:
	cd tests/ && $(MAKE)

clean:
	rm sudoku_solver && cd obj/ && rm *

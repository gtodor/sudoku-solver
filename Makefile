.PHONY: all tests clean

all: sudoku_solver

sudoku_solver: obj/main.o obj/cell.o obj/grid.o obj/solver.o
	g++ -Wall -Wextra $^ -o $@

obj/main.o: main.cpp
	g++ -Wall -Wextra -c main.cpp -o $@
obj/cell.o: cell.cpp cell.hpp
	g++ -Wall -Wextra -c cell.cpp -o $@
obj/grid.o: grid.cpp grid.hpp
	g++ -Wall -Wextra -c grid.cpp -o $@
obj/solver.o: solver.cpp solver.hpp
	g++ -Wall -Wextra -c solver.cpp -o $@

tests:
	cd tests/ && $(MAKE)

clean:
	cd obj/ && rm *

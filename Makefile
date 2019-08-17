.PHONY: all tests clean

all: sudoku_solver

sudoku_solver: main.o grid.o solver.o cell.o domain.o
	g++ -Wall -Wextra -g -o $@ $^ 

main.o: main.cpp
	g++ -Wall -Wextra -g -c main.cpp -o $@
grid.o: grid.cpp grid.hpp
	g++ -Wall -Wextra -g -c grid.cpp -o $@
solver.o: solver.cpp solver.hpp
	g++ -Wall -Wextra -g -c solver.cpp -o $@

cell.o: cell.cpp cell.hpp
	g++ -Wall -Wextra -g -c cell.cpp -o $@

domain.o: domain.cpp domain.hpp
	g++ -Wall -Wextra -g -c domain.cpp -o $@

tests:
	cd tests/ && $(MAKE)

clean:
	rm sudoku_solver *.o

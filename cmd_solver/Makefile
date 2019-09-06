.PHONY: all clean

all: sudoku_solver_cmd

sudoku_solver_cmd: obj/sudoku_solver_cmd.o obj/grid.o obj/solver.o obj/cell.o obj/domain.o
	g++ -Wall -Wextra -g -o $@ $^ 

obj/sudoku_solver_cmd.o: sudoku_solver_cmd.cpp
	g++ -Wall -Wextra -g -c sudoku_solver_cmd.cpp -o $@ -I../src/

obj/grid.o: ../src/grid.cpp ../src/grid.hpp
	g++ -Wall -Wextra -g -c ../src/grid.cpp -o $@

obj/solver.o: ../src/solver.cpp ../src/solver.hpp
	g++ -Wall -Wextra -g -c ../src/solver.cpp -o $@

obj/cell.o: ../src/cell.cpp ../src/cell.hpp
	g++ -Wall -Wextra -g -c ../src/cell.cpp -o $@

obj/domain.o: ../src/domain.cpp ../src/domain.hpp
	g++ -Wall -Wextra -g -c ../src/domain.cpp -o $@


clean:
	rm sudoku_solver_cmd
	(cd obj && rm *)

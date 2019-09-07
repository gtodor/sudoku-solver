all: solver_server

.PHONY: all clean

solver_server: solver_ext
	cp ext/sudoku-rice/sudoku_solver.so server/

solver_ext: obj/solver.o obj/grid.o obj/cell.o obj/domain.o
	(cd ext/sudoku-rice && $(MAKE))

obj/grid.o: src/grid.cpp src/grid.hpp
	g++ -Wall -Wextra -g -fPIC -c src/grid.cpp -o $@

obj/solver.o: src/solver.cpp src/solver.hpp
	g++ -Wall -Wextra -g -fPIC -c src/solver.cpp -o $@

obj/cell.o: src/cell.cpp src/cell.hpp
	g++ -Wall -Wextra -g -fPIC -c src/cell.cpp -o $@

obj/domain.o: src/domain.cpp src/domain.hpp
	g++ -Wall -Wextra -g -fPIC -c src/domain.cpp -o $@

clean:
	(cd obj && rm *)
	(cd ext/sudoku-rice && $(MAKE) clean)
	(cd server && rm sudoku_solver.so)

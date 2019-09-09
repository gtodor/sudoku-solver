all: solver_ext

.PHONY: all clean

solver_ext: lib/libsudokusolvr.a
	(cd ext/sudoku-rice && $(MAKE))

lib/libsudokusolvr.a: obj/solver.o obj/grid.o obj/cell.o obj/domain.o
	ar rcs $@ $^

obj/grid.o: src/grid.cpp include/grid.hpp
	g++ -Wall -Wextra -g -fPIC -c src/grid.cpp -o $@ -Iinclude

obj/solver.o: src/solver.cpp include/solver.hpp
	g++ -Wall -Wextra -g -fPIC -c src/solver.cpp -o $@ -Iinclude

obj/cell.o: src/cell.cpp include/cell.hpp
	g++ -Wall -Wextra -g -fPIC -c src/cell.cpp -o $@ -Iinclude

obj/domain.o: src/domain.cpp include/domain.hpp
	g++ -Wall -Wextra -g -fPIC -c src/domain.cpp -o $@ -Iinclude

clean:
	(cd obj && rm *)
	(cd lib && rm *)
	(cd ext/sudoku-rice && $(MAKE) clean)


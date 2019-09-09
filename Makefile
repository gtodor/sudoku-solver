all: solver_ext

.PHONY: all clean

solver_ext: lib/libsudokusolvr.a
	(cd ext/sudoku-rice && $(MAKE) && cp sudoku_solvr.so ../../server/)

lib/libsudokusolvr.a: obj/solver.o obj/grid.o obj/cell.o obj/domain.o | obj
	ar rcs $@ $^

obj/grid.o: src/grid.cpp include/grid.hpp | obj
	g++ -Wall -Wextra -g -fPIC -c src/grid.cpp -o $@ -Iinclude

obj/solver.o: src/solver.cpp include/solver.hpp | obj
	g++ -Wall -Wextra -g -fPIC -c src/solver.cpp -o $@ -Iinclude

obj/cell.o: src/cell.cpp include/cell.hpp | obj
	g++ -Wall -Wextra -g -fPIC -c src/cell.cpp -o $@ -Iinclude

obj/domain.o: src/domain.cpp include/domain.hpp | obj
	g++ -Wall -Wextra -g -fPIC -c src/domain.cpp -o $@ -Iinclude

obj:
	mkdir -p $@

clean:
	(cd obj && rm *)
	(cd lib && rm *)
	(cd server && rm *.so)
	(cd ext/sudoku-rice && $(MAKE) clean)


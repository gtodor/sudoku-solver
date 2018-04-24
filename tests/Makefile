all:test_cell test_grid

test_cell: ../obj/test_cell.o ../obj/cell.o
	g++ -Wall -Wextra $^ -o $@

test_grid: ../obj/test_grid.o ../obj/grid.o ../obj/cell.o
	g++ -Wall -Wextra $^ -o $@

../obj/test_cell.o: test_cell.cpp
	g++ -c test_cell.cpp -o ../obj/test_cell.o
../obj/cell.o: ../cell.cpp ../cell.hpp
	g++ -c ../cell.cpp -o ../obj/cell.o
../obj/test_grid.o: test_grid.cpp
	g++ -c $^ -o $@
../obj/grid.o: ../grid.cpp ../grid.hpp
	g++ -c ../grid.cpp -o ../obj/grid.o

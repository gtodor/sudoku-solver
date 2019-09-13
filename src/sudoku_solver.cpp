#include <rice/Class.hpp>
#include <rice/Array.hpp>
#include <rice/Object.hpp>
#include <vector>
#include <iostream>
#include "solver.hpp"
using namespace Rice;


template<>
std::vector<int> from_ruby< std::vector<int> > (Object o)   {
    Array a(o);
    std::vector<int> v;
    for(Array::iterator aI = a.begin(); aI != a.end(); ++aI)
        v.push_back(from_ruby<int>(*aI));
    return v;
}

Array rice_solve(std::vector<int> input){
  Array result;
  if(input.size() != 81){
    return result;
  }
  try {
    SDK_Grid grid(input);
    SDK_Solver solver;
    if (solver.solve(grid)) {
      SDK_Grid solution = solver.getSolution();
      std::vector<int> data = solution.getData();
      for(int i = 0; i < 81; i++){
        result.push(to_ruby(data[i]));
      }
    }
    return result;
  } catch(const char* e) {
    return result;
  }
}


extern "C"

void Init_sudoku_solver() {
    Class rb = define_class("SudokuSolver")
        .define_method("solve", &rice_solve);
}

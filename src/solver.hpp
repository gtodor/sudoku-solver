#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "grid.hpp"

class SDK_Solver{
private:
  SDK_Grid solution;
public:
  SDK_Solver();
  bool solve(SDK_Grid& grid);
  SDK_Grid getSolution();
};


#endif//SOLVER_HPP

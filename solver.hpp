#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "grid.hpp"
#include <queue>

class SDK_Solver{
private:
  std::queue<SDK_Grid> solutions;
  void solve(SDK_Grid& grid, int index);
public:
  void solve(SDK_Grid& grid);
  SDK_Grid popSolution();
  bool hasSolutions() const;
};


#endif//SOLVER_HPP

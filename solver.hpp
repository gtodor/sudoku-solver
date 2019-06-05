#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "grid.hpp"
#include <queue>

class sdk_solver{
private:
  std::queue<std::vector<int>> solutions;//when you find a solution you copy the current state of the grid in a new grid that you push in solutions
  void solve(sdk_grid& grid, int index);
public:
  void solve(sdk_grid& grid);
  std::vector<int> popSolution();
  bool hasSolutions() const;
};


#endif//SOLVER_HPP

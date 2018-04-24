#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "grid.hpp"
#include <vector>

class sdk_solver{
private:
  sdk_grid& m_grid;
  int m_index;
  std::vector<sdk_grid> solutions;//when you find a solution you copy the current state of the grid in a new grid that you push in solutions
public:
  sdk_solver(sdk_grid& grid);
  ~sdk_solver();
  int index();
  bool solve();
  void print();

};


#endif//SOLVER_HPP

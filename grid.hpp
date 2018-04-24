#ifndef GRID_HPP
#define GRID_HPP

#include "cell.hpp"

class sdk_sector{
private:
  std::vector<sdk_cell*> cells_refs;
public:
  sdk_sector();
  ~sdk_sector();
  void add(sdk_cell* cell);
  void update(int value, action a);
  void print();
  void print_cells_details();
};

class sdk_grid{
private:
  std::vector<sdk_cell> matrix;
  std::vector<sdk_sector> sectors;
  void update_column(int j, int value, action a);
  void update_row(int i, int value, action a);
  void update_sector(sdk_sector& sector, int value, action a);
public:
  sdk_grid(std::vector<int>& from);
  ~sdk_grid();
  sdk_cell& cell_at(int index);
  void update(int i, int j, int value, action a);
  void print();
  void print_sectors_details();
  void print_cells(int number);
  void print_sectors();
};


#endif//GRID_HPP

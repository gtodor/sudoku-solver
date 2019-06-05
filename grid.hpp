#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>

class sdk_grid{
private:
  std::vector<int> data;
  std::vector<string> domains;
  bool propagate_column(int column, int value);
  bool propagate_row(int row, int value);
  bool propagate_sector(int row, int column, int value);
  bool propagate(int row, int column, int value);
public:
  sdk_grid(std::vector<int>& from);
  sdk_grid(const sdk_grid& from);
  bool set(int index, int value);
  int get(int index) const;
  std::string getDomain(int index) const;
  std::vector<int> getData() const;
};


#endif//GRID_HPP

#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>
#include "cell.hpp"

class SDK_Grid{
private:
  std::vector<SDK_Cell> data;
  bool propagateRow(int row, int value);
  bool propagateColumn(int column, int value);
  bool propagateSector(int sector, int value);
public:
  SDK_Grid(std::vector<int>& from);
  SDK_Grid(const SDK_Grid& from);
  SDK_Grid();
  bool propagate(int row, int column, int sector, int value);
  bool isCompleted();
  bool set(int row, int column, int value);
  void print();
  std::string toString();
  std::vector<int> getSingleValuedDomainCellsIndexes();
  bool tryToSetSolutionInSingleValuedDomain(int index);
  int getSmallestDomainCellIndex();
  std::vector<int> getCellDomain(int index);
};


#endif//GRID_HPP

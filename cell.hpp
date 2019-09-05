#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include "domain.hpp"

class SDK_Cell {
private:
  int solution;
  SDK_Domain domain;
  int sector;
  bool fixed;

public:
  SDK_Cell(int sector);
  SDK_Cell(const SDK_Cell& from);
  bool removeFromDomain(int value);
  int getSector();
  bool isFixed();
  void setSolution(int solution);
  int getSolution();
  void print();
  bool isDomainSingleValued();
  bool tryToSetSolutionInSingleValuedDomain();
  int getDomainSize();
  std::vector<int> getDomainValues();
};

#endif //CELL_HPP

#ifndef CELL_HPP
#define CELL_HPP

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
  int getPossibleSolution();
  int getSector();
  bool isFixed();
  void setSolution(int solution);
  int getSolution();
  void print();
};

#endif //CELL_HPP

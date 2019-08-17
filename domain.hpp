#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <vector>

class SDK_Domain {
  std::vector<int> domain;
  int nonZeroValues;

public:
  SDK_Domain();
  SDK_Domain(const SDK_Domain& from);
  bool remove(int value);
  int getPossibleSolution();
  bool isEmpty();
  void print();
};

#endif //DOMAIN_HPP

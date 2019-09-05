#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include <vector>

class SDK_Domain {
  std::vector<int> domain;
  int nonZeroValues;

public:
  SDK_Domain();
  SDK_Domain(const SDK_Domain& from);
  void reduceToSingleValue(int value);
  bool remove(int value);
  bool isEmpty();
  void print();
  bool isSingleValued();
  int getSize();
  std::vector<int> getPossibleSolutions();
};

#endif //DOMAIN_HPP

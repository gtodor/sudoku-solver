#include <iostream>
#include <string>
#include "cell.hpp"

using namespace std;

SDK_Cell::SDK_Cell(int sector) :
  solution(0),
  domain(),
  sector(sector),
  fixed(false) {}

SDK_Cell::SDK_Cell(const SDK_Cell& from) :
  solution(from.solution),
  domain(from.domain),
  sector(from.sector),
  fixed(from.fixed) {}

bool SDK_Cell::removeFromDomain(int value) {
  if(!fixed){
    return domain.remove(value);
  }
  return true;
}

int SDK_Cell::getSector() {
  return sector;
}

bool SDK_Cell::isFixed() {
  return fixed;
}
  
void SDK_Cell::setSolution(int solution) {
  this->solution = solution;
  fixed = true;
}

int SDK_Cell::getSolution() {
  return solution;
}

int SDK_Cell::getPossibleSolution() {
  return domain.getPossibleSolution();
}

void SDK_Cell::print() {
  if(isFixed()){
    cout<<solution;
    for (int i=0; i<8; i++){
      cout<< " ";
    }
  } else {
    domain.print();
  }
}

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
  domain.reduceToSingleValue(solution);
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
    const string mangenta("\033[0;35m");
    const string reset("\033[0m");
    cout<<mangenta<<solution<<reset;
    for (int i=0; i<8; i++){
      cout<< " ";
    }
  } else {
    domain.print();
  }
}

bool SDK_Cell::isDomainSingleValued(){
  return domain.isSingleValued();
}

bool SDK_Cell::tryToSetSolutionInSingleValuedDomain() {
  if (!domain.isSingleValued()) {
    return false;
  }
  solution = domain.getPossibleSolution();
  fixed = true;
  return true;
}

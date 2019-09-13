#include <iostream>
#include <sstream>
#include "domain.hpp"

using namespace std;

SDK_Domain::SDK_Domain() : domain{1,2,3,4,5,6,7,8,9}, nonZeroValues(9) {}

SDK_Domain::SDK_Domain(const SDK_Domain& from):
  domain(from.domain),
  nonZeroValues(from.nonZeroValues) {}

bool SDK_Domain::isEmpty() {
  if(nonZeroValues <= 0){
    return true;
  }
  return false;
}

void SDK_Domain::reduceToSingleValue(int value) {
  for (int i=0; i<9; i++) {
    if (i != value - 1 && domain[i] != 0) {
      domain[i] = 0;
      nonZeroValues--;
    }
  }
}

bool SDK_Domain::remove(int value) {
  if (isEmpty()){
    return false;
  }

  if(domain[value - 1] != 0){
    domain[value - 1] = 0;
    nonZeroValues--;
  }

  return !isEmpty();
}

void SDK_Domain::print(){
  stringstream resultToPrint;
  for(int i=0; i<9; i++){
    if(domain[i] != 0){
      resultToPrint << domain[i];
    }
  }
  string resultFull = "123456789";
  int leftSpaces = resultFull.size() - resultToPrint.str().size();
  for(int i=0; i<leftSpaces; i++){
    resultToPrint << " ";
  }

  cout<<resultToPrint.str();
}
  
  
bool SDK_Domain::isSingleValued() {
  return nonZeroValues == 1;
}

int SDK_Domain::getSize() {
  return nonZeroValues;
}

vector<int> SDK_Domain::getPossibleSolutions() {
  vector<int> result;
  for (int i=0; i<9; i++) {
    if (domain[i] != 0) {
      result.push_back(domain[i]);
    }
  }
  return result;
}

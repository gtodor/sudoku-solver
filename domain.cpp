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

int SDK_Domain::getPossibleSolution() {
  if(isEmpty()){
    return 0;
  }
  
  for(int i=0; i<9; i++){
    if (domain[i] != 0){
      return domain[i];
    }
  }
  return 0;
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
  
  

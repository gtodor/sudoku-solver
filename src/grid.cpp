#include <iostream>
#include <cassert>
#include <sstream>
#include "grid.hpp"

using namespace std;

SDK_Grid::SDK_Grid(vector<int>& from) {
  assert(from.size() == 81);
  data.reserve(81);
  for(int row=0; row<9; row++){
    for (int column=0; column<9; column++){
      int sector_row = row / 3;
      int sector_column = column / 3;
      int sector = sector_row * 3 + sector_column;
      SDK_Cell cell(sector);
      int index = row*9+column;
      if (from[index] != 0) {
        cell.setSolution(from[index]);
      }
      data.push_back(cell);
    }
  }
  for(int row=0; row<9; row++){
    for(int column=0; column<9; column++) {
      if(data[row*9+column].isFixed()){
	      int solution = data[row*9+column].getSolution();
	      int sector = data[row*9+column].getSector();
	      if (!propagate(row, column, sector, solution)) {
	        throw "input data is wrong";
	      }
      }
    }
  }
}

SDK_Grid::SDK_Grid(const SDK_Grid& from) : data(from.data) {}

SDK_Grid::SDK_Grid() : data() {}

bool SDK_Grid::propagateColumn(int row, int column, int value) {
  for(int r=0; r<9; r++){
    if(r == row) {
      continue;
    }
    if(!data[r*9+column].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagateRow(int row, int column, int value) {
  for(int col=0; col<9; col++){
    if(col == column) {
      continue;
    }
    if(!data[row*9+col].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagateSector(int row, int column, int sector, int value) {
  for(int i = 0; i < 81; i++){
    int current_row = i/9;
    int current_column = i%9;
    if(current_row == row && current_column == column) {
      continue;
    } 
    if(data[i].getSector() == sector && !data[i].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagate(int row, int column, int sector, int value){
  if(!propagateColumn(row, column, value)) {
    return false;
  }
  if(!propagateRow(row, column, value)) {
    return false;
  }
  if(!propagateSector(row, column, sector, value)){
    return false;
  }
  return true;
}

bool SDK_Grid::isCompleted() {
  for(int i=0; i<81; i++) {
    if(!data[i].isFixed()) {
      return false;
    }
  }
  return true;
}

void SDK_Grid::print() {
  for(int row=0; row<9; row++){
    for(int column=0; column<9; column++){
      data[row*9+column].print();
      cout<<" ";
    }
    cout<<endl;
  }
}

bool SDK_Grid::set(int row, int column, int value) {
  data[row*9+column].setSolution(value);
  int sector = data[row*9+column].getSector();
  return propagate(row, column, sector, value);  
}

vector<int> SDK_Grid::getSingleValuedDomainCellsIndexes() {
  vector<int> result;
  for (int index=0; index<81; index++) {
    if (data[index].isDomainSingleValued() && !data[index].isFixed()) {
      result.push_back(index);
    }
  }
  return result;
}

bool SDK_Grid::tryToSetSolutionInSingleValuedDomain(int index){
  if (data[index].tryToSetSolutionInSingleValuedDomain()) {
    int solution = data[index].getSolution();
    int row = index / 9;
    int column = index % 9;
    int sector = data[index].getSector();
    return propagate(row, column, sector, solution);
  }
  return false;
}

string SDK_Grid::toString() {
  stringstream result;
  for (int index = 0; index < 81; index++) {
    result << data[index].getSolution();
  }
  return result.str();
}


int SDK_Grid::getSmallestDomainCellIndex() {
  int smallestDomainIndex = 0;
  while (data[smallestDomainIndex].isFixed()) {
    smallestDomainIndex++;
  }
  int smallestDomainSize = data[smallestDomainIndex].getDomainSize();
  for (int i=0; i<81; i++) {
    if (!data[i].isFixed() && data[i].getDomainSize() < smallestDomainSize) {
      smallestDomainSize = data[i].getDomainSize();
      smallestDomainIndex = i;
    }
  }
  
  return smallestDomainIndex;
}

vector<int> SDK_Grid::getCellDomain(int index) {
  return data[index].getDomainValues();
}

vector<int> SDK_Grid::getData() {
  vector<int> result;
  for (int i=0; i<81; i++) {
    result.push_back(data[i].getSolution());
  }
  return result;
}

#include <iostream>
#include <cassert>
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

bool SDK_Grid::propagateColumn(int column, int value) {
  for(int row=0; row<9; row++){
    if(!data[row*9+column].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagateRow(int row, int value) {
  for(int column=0; column<9; column++){
    if(!data[row*9+column].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagateSector(int sector, int value) {
  for(int i = 0; i < 81; i++){
    if(data[i].getSector() == sector && !data[i].removeFromDomain(value)) {
      return false;
    }
  }
  return true;
}

bool SDK_Grid::propagate(int row, int column, int sector, int value){
  if(!propagateColumn(column, value)) {
    return false;
  }
  if(!propagateRow(row, value)) {
    return false;
  }
  if(!propagateSector(sector, value)){
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

void SDK_Grid::set(int row, int column, int value) {
  data[row*9+column].setSolution(value);
  int sector = data[row*9+column].getSector();
  if(!propagate(row, column, sector, value)){
    throw "ERROR: this value is not valid";
  }
}

vector<int> SDK_Grid::getSingleValuedDomainCellsIndexes() {
  vector<int> result;
  for (int index=0; index<81; index++) {
    if (data[index].isDomainSingleValued()) {
      result.push_back(index);
    }
  }
  return result;
}

void SDK_Grid::tryToSetSolutionInSingleValuedDomain(int index){
  if (data[index].tryToSetSolutionInSingleValuedDomain()) {
    int solution = data[index].getSolution();
    int row = index / 9;
    int column = index % 9;
    int sector = data[index].getSector();
    if (!propagate(row, column, sector, solution)){
      throw "ERROR: this value is not valid";
    }
  }
}

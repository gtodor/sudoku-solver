#include <iostream>
#include <unistd.h>
#include <vector>
#include "solver.hpp"

using namespace std;

SDK_Solver::SDK_Solver() {}

bool SDK_Solver::solve(SDK_Grid& grid){
  if(grid.isCompleted()){
    solution = grid;;
    return true;
  }
  
  vector<int> singleValuedDomainCellsIndexes = grid.getSingleValuedDomainCellsIndexes();
  while(!singleValuedDomainCellsIndexes.empty()){
    for(int index : singleValuedDomainCellsIndexes){
      if (!grid.tryToSetSolutionInSingleValuedDomain(index)) {
	return false;
      }
    }
    if (grid.isCompleted()){
      solution = grid;
      return true;
    }
    singleValuedDomainCellsIndexes = grid.getSingleValuedDomainCellsIndexes();
  }

  int indexCellSmallestDomain = grid.getSmallestDomainCellIndex();
  vector<int> smallestDomain = grid.getCellDomain(indexCellSmallestDomain);
  for (unsigned int i=0; i<smallestDomain.size(); i++) {
    int value = smallestDomain[i];
    int row = indexCellSmallestDomain / 9;
    int column = indexCellSmallestDomain % 9;
    SDK_Grid copyGrid(grid);
    if (!copyGrid.set(row, column, value)){
      continue;
    }
    if (solve(copyGrid)) {
      return true;
    }
  }
  
  return false;
}

SDK_Grid SDK_Solver::getSolution(){
  return solution;
}

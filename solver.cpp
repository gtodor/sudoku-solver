#include <iostream>
#include <unistd.h>
#include <vector>
#include "solver.hpp"

using namespace std;

void SDK_Solver::solve(SDK_Grid& grid){
  if(grid.isCompleted()){
    solutions.push(grid);
    return;
  }
  SDK_Grid copyGrid(grid);
  vector<int> singleValuedDomainCellsIndexes = copyGrid.getSingleValuedDomainCellsIndexes();
  while(!singleValuedDomainCellsIndexes.empty()){
    for(int index : singleValuedDomainCellsIndexes){
      copyGrid.tryToSetSolution(index);
    }
    if (copyGrid.isCompleted()){
      solutions.push(copyGrid);
      return;
    }
    singleValuedDomainCellsIndexes = copyGrid.getSingleValuedDomainCellsIndexes();
  }
  //at this point there are no more single valued domains and the sudoku is not completed
  //search for pairs and update the grid;
  //solve(grid, index);
}

void SDK_Solver::solve(SDK_Grid& grid, int index){
    // if(index == 81){
    //     print_solution(grid.getData());
    //     solutions.push(grid.getData());
    // }else{
    //     string domain = grid.getDomain(index);
    //     for(unsigned int i=0; i<=domain.size(); i++){
    //         SDK_Grid tmp_grid(grid);
    //         int tmp_index = index;
    //         int value = domain[i] - '0';

    //         if(tmp_grid.set(tmp_index, value)){ 
    //             print_solution(tmp_grid.getData());
    //             do{
    //                 tmp_index++;
    //             }while(tmp_index < 81 && tmp_grid.get(tmp_index) != 0);
    //             solve(tmp_grid, tmp_index);
    //         }
    //     }
    // }
}

bool SDK_Solver::hasSolutions() const{
  return !solutions.empty();  
}

SDK_Grid SDK_Solver::popSolution(){
  SDK_Grid solution = solutions.front();
  solutions.pop();
  return solution;
}

#include <iostream>
#include <unistd.h>
#include "solver.hpp"

using namespace std;

void sdk_solver::solve(sdk_grid& grid){
    int index = 0;
    while(index < 81 && grid.get(index) != 0){
        index++;
    }
    solve(grid, index);
}

void print_solution(vector<int> data){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<data[i*9+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void sdk_solver::solve(sdk_grid& grid, int index){
    if(index == 81){
        print_solution(grid.getData());
        solutions.push(grid.getData());
    }else{
        string domain = grid.getDomain(index);
        for(unsigned int i=0; i<=domain.size(); i++){
            sdk_grid tmp_grid(grid);
            int tmp_index = index;
            int value = domain[i] - '0';

            if(tmp_grid.set(tmp_index, value)){ 
                print_solution(tmp_grid.getData());
                do{
                    tmp_index++;
                }while(tmp_index < 81 && tmp_grid.get(tmp_index) != 0);
                solve(tmp_grid, tmp_index);
            }
        }
    }
}

bool sdk_solver::hasSolutions() const{
    return !solutions.empty();
}

std::vector<int> sdk_solver::popSolution(){
    std::vector<int> solution = solutions.front();
    solutions.pop();
    return solution;
}

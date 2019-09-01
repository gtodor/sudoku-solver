#include <iostream>
#include <vector>
#include "solver.hpp"

using namespace std;

int main(){
    vector<int> matrix  {
      0,0,1,0,0,9,0,0,0,
      4,0,9,1,7,0,0,0,2,
      0,3,5,0,4,8,1,0,0,
      9,0,6,0,0,0,3,7,0,
      1,0,0,7,3,6,4,0,9,
      3,0,0,9,8,2,0,0,0,
      0,0,0,0,2,7,0,0,4,
      6,9,4,0,1,3,0,5,7,
      0,7,2,0,0,0,0,0,0
    };

    // vector<int> matrix {
    //     0,0,0,0,0,0,1,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     6,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0,
    //     0,0,0,0,0,0,0,0,0
    // };


    // for(int i=0; i<81; i++){
    //     matrix.push_back(temp[i]);
    // }
    try{
      cout<<"building grid..."<<endl;
      SDK_Grid grid(matrix);
      cout<<"grid finished building"<<endl;
      grid.print();

      cout<<"solving sudoku"<<endl;
      SDK_Solver solver;
      solver.solve(grid);
      SDK_Grid solution = solver.popSolution();
      solution.print();
    } catch (const char* e) {
      cout<<"exception: "<<e<<endl;
    }

    return 0;
}

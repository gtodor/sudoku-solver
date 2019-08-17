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
    } catch (const char* e) {
      cout<<"exception: "<<e<<endl;
    }

    // sdk_solver solver;
    // solver.solve(grid);
    // if(solver.hasSolutions() == false){
    //     cout<<"problem does not have solutions"<<endl;
    // } else {
    //     cout<<endl;
    //     vector<int> solution = solver.popSolution();
    //     for(int i = 0; i<9; i++){
    //         for(int j = 0; j<9; j++){
    //             cout<<solution[i*9+j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    return 0;
}

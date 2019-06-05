#include <iostream>
#include <vector>
#include "solver.hpp"

using namespace std;

int main(){
    //int temp[] = {
    //    1,0,7,6,4,9,3,0,2,
    //    2,0,0,3,7,5,0,1,6,
    //    3,0,6,8,2,1,4,0,0,
    //    0,1,0,0,9,6,7,3,8,
    //    7,6,3,0,1,8,0,4,9,
    //    0,0,0,0,3,7,6,0,1,
    //    6,7,2,1,5,3,0,0,4,
    //    8,3,1,9,6,4,0,0,0,
    //    0,0,0,7,8,2,1,6,3
    //};

    int temp[] = {
        0,0,0,0,0,0,1,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        6,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0
    };

    vector<int> matrix;
    for(int i=0; i<81; i++){
        matrix.push_back(temp[i]);
    }
    sdk_grid grid(matrix);

    sdk_solver solver;
    solver.solve(grid);
    if(solver.hasSolutions() == false){
        cout<<"problem does not have solutions"<<endl;
    } else {
        cout<<endl;
        vector<int> solution = solver.popSolution();
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout<<solution[i*9+j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

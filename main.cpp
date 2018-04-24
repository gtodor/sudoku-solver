#include <iostream>
#include "solver.hpp"

using namespace std;

int main(){
  int temp[] = {0,0,4,0,0,1,2,0,0,
		0,0,1,0,0,6,0,3,0,
		0,2,0,0,9,0,0,7,1,
		0,1,0,0,0,0,0,0,0,
		6,0,0,7,0,9,0,0,3,
		0,0,0,0,0,0,0,4,0,
		5,7,0,0,1,0,0,6,0,
		0,3,0,6,0,0,5,0,0,
		0,0,2,3,0,0,7,0,0};

  vector<int> matrix;
  for(int i=0; i<81; i++){
    matrix.push_back(temp[i]);
  }
  sdk_grid grid(matrix);

  sdk_solver solver(grid);
  solver.print();
  cout<<endl;
  bool res = solver.solve();
  if(res==false){
    cout<<"problem does not have solutions"<<endl;
  }
  
  return 0;
}

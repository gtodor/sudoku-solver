#include <iostream>
#include <vector>
#include "../grid.hpp"

using namespace std;

int main(){

  int temp[] = {0,0,0,2,0,0,0,0,5,
		0,4,0,0,0,0,0,0,9,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,7,0,0,0,
		0,0,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,9,0,0,
		0,5,0,0,0,0,0,0,1,
		0,0,0,9,0,0,0,0,0};

  vector<int> matrix;
  for(int i=0; i<81; i++){
    matrix.push_back(temp[i]);
  }
  sdk_grid grid(matrix);
  grid.print();
  //grid.print_sectors();
  //grid.print_cells();
  grid.print_sectors_details();
  
  return 0;
}

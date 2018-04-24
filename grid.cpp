#include <iostream>
#include <cassert>
#include "grid.hpp"

using namespace std;

sdk_sector::sdk_sector(){

}

sdk_sector::~sdk_sector(){

}

void sdk_sector::add(sdk_cell* cell){
  cells_refs.push_back(cell);
}

void sdk_sector::update(int value, action a){
  for(int i=0; i<cells_refs.size(); i++){
    cells_refs[i]->update(value, a);
  }
}

//prints the degrees of liberty of each cell in sector
void sdk_sector::print_cells_details(){
  for(int i=0; i<cells_refs.size(); i++){
    cout<<"cell "<<i<<endl;
    cells_refs[i]->print();
  }
}

//prints the sector's cells in a matrix display
void sdk_sector::print(){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout<<cells_refs[i*3+j]->current_value()<<" ";
    }
    cout<<endl;
  }
}


sdk_grid::sdk_grid(vector<int>& from){
  for(int i=0; i<9;i++){
    sdk_sector sector;
    sectors.push_back(sector);
  }
  cout<<"sectors init: "<<endl;
  
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      sdk_cell cell;
      if(from[i*9+j]==0){
	cell.set_current_value(from[i*9+j]);
	cell.set_fixed(false);
      }
      else if(from[i*9+j] > 0){
	cell.set_fixed(true);
	cell.set_current_value(from[i*9+j]);
      }else{
	return;
      }
      matrix.push_back(cell);
    }
  }

  //fill sectors with refs
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      int sector_i=i/3;
      int sector_j=j/3;
      sectors[sector_i*3+sector_j].add(&matrix[i*9+j]);
    }
  }

  //update the cells to take the inputs in consideration
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(matrix[i*9+j].current_value() != 0){
	update(i,j,matrix[i*9+j].current_value(),DESTROY);
      }
    }
  }
}

sdk_grid::~sdk_grid(){

}

void sdk_grid::update(int i, int j, int value, action a){
  update_column(j,value,a);
  update_row(i,value,a);
  int sector_i = i/3;
  int sector_j = j/3;
  //cout<<"update sector("<<sector_i<<","<<sector_j<<"): "<<endl;
  update_sector(sectors[sector_i*3+sector_j],value,a);
}

void sdk_grid::update_column(int j, int value, action a){
  //cout<<"update column "<<j<<endl;
  for(int i=0; i<9; i++){
    matrix[i*9+j].update(value,a);
  }
}

void sdk_grid::update_row(int i, int value, action a){
  //cout<<"update row "<<i<<endl;
  for(int j=0; j<9; j++){
    matrix[i*9+j].update(value,a);
  }
}

void sdk_grid::update_sector(sdk_sector& sector, int value, action a){
  sector.update(value,a);
}

//prints all the sudoku grid in a matrix display
void sdk_grid::print(){
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      cout<<matrix[i*9+j].current_value()<<" ";
    }
    cout<<endl;
  }
}

//prints the details of each sector (is not necessarily important, use print_cells instead for all matrix )
void sdk_grid::print_sectors_details(){
  cout<<endl<<"sectors: "<<endl;
  for(int i=0; i<sectors.size(); i++){
    cout<<"sector "<<i<<" :"<<endl;
    sectors[i].print_cells_details();
    cout<<endl;
  }
}

//prints all the submatrix in each sector
void sdk_grid::print_sectors(){
  for(int i=0; i<sectors.size(); i++){
    cout<<endl<<"sector("<<i<<"):"<<endl;
    sectors[i].print();
    cout<<endl;
  }
}

//prints the details of each cell
void sdk_grid::print_cells(int number){
  assert(number<matrix.size());
  for(int i=0; i<number; i++){
    cout<<"cell "<<i<<endl;
    matrix[i].print();
    cout<<endl;
  }
}

sdk_cell& sdk_grid::cell_at(int index){
  return matrix[index];
}

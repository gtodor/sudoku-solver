#include <iostream>
#include <unistd.h>
#include "solver.hpp"

using namespace std;

sdk_solver::sdk_solver(sdk_grid& grid): m_grid(grid),m_index(0){
  while(m_grid.cell_at(m_index).fixed()){
    m_index++;
  }
}

sdk_solver::~sdk_solver(){

}

int sdk_solver::index(){
  return m_index;
}

bool sdk_solver::solve(){
  if(m_index == 81){
    //this is a solution
    //for now just print it
    cout<<"solution:"<<endl;
    m_grid.print();
    cout<<endl;
    return true;
  }else{
    vector<int> degrees = m_grid.cell_at(m_index).freedom_degrees();
    bool found=false;
    for(int i=0; i<degrees.size(); i++){
      //sleep(1);
      if(degrees[i] == 3){
	m_grid.cell_at(m_index).set_current_value(i+1);
	int gridi=m_index/9;
	int gridj=m_index%9;
	m_grid.update(gridi,gridj,i+1,DESTROY);
	int original = m_index;
	do{
	  m_index++;
	  if(m_index == 81){
	    cout<<"solution:"<<endl;
	    m_grid.print();
	    cout<<endl;
	    return true;
	  }
	}while(m_grid.cell_at(m_index).fixed() == true);
	//m_grid.print();
	//cout<<endl;
	//m_grid.print_cells(3);
	if(solve()){
	  found=true;
	  m_index=original;
	  m_grid.cell_at(m_index).set_current_value(0);
	  m_grid.update(gridi,gridj,i+1,ADD);
	  
	}else{
	  m_index=original;
	  m_grid.cell_at(m_index).set_current_value(0);
	  m_grid.update(gridi,gridj,i+1,ADD);
	}
      }
    }
    return found;
  }
    
}

void sdk_solver::print(){
  m_grid.print();
}

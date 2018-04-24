#include <iostream>
#include "../cell.hpp"

using namespace std;


int main(){

  sdk_cell cell;
  cell.print();
  
  cout<<endl;

  cell.set_current_value(8);
  cell.print();
  
  cout<<"fixed = "<<cell.fixed()<<endl;
  cout<<"current value = "<<cell.current_value()<<endl;
  cout<<endl;

  cell.set_fixed(true);
  cout<<"fixed = "<<cell.fixed()<<endl;
  cout<<"current value = "<<cell.current_value()<<endl;
  cell.print();
  cout<<endl;
  
  cell.update(3,DESTROY);
  cell.print();

  cout<<endl;

  cell.update(3,ADD);
  cell.print();
  
  return 0;
}

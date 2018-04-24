#include "cell.hpp"
#include <cassert>
#include <iostream>

using namespace std;

sdk_cell::sdk_cell(): m_fixed(false),m_current_value(0), m_index(0){
  assert(m_freedom_degrees.size() == 0);
  for(int i=0; i<9; i++){
    m_freedom_degrees.push_back(3);
  }
}

sdk_cell::~sdk_cell(){

}

//show the domain and the freedom degrees
void sdk_cell::print(){
  for(int i=0; i<9; i++){
    cout<<"domain["<<i+1<<"] has "<<m_freedom_degrees[i]<<" freedom degrees"<<endl;
  }
}

int sdk_cell::current_value(){
  return m_current_value;
}

bool sdk_cell::fixed(){
  return m_fixed;
}

void sdk_cell::set_current_value(int value){
  m_current_value = value;
}

void sdk_cell::set_fixed(bool val){
  m_fixed = val;
}

void sdk_cell::update(int value, action a){
  switch(a){
  case ADD:{
    m_freedom_degrees[value-1]++;
  }break;
  case DESTROY:{
    m_freedom_degrees[value-1]--;
  }break;
  default:break;
  }
}

vector<int> sdk_cell::freedom_degrees(){
  return m_freedom_degrees;
}

int sdk_cell::index(){
  return m_index;
}

void sdk_cell::set_ind(int index){
  m_index = index;
}

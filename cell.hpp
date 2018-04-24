#ifndef CELL_HPP
#define CELL_HPP

#include <vector>

enum action{
  DESTROY,
  ADD
};

class sdk_cell{
private:
  std::vector<int> m_freedom_degrees;
  bool m_fixed;
  int m_current_value;
  int m_index;
public:
  sdk_cell();
  ~sdk_cell();
  int current_value();
  bool fixed();
  void set_current_value(int value);
  void set_fixed(bool val);
  void update(int value, action a);//value represents the index in the m_freedom_degrees vector
  void print();
  std::vector<int> freedom_degrees();
  int index();
  void set_ind(int index);
};


#endif//CELL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "solver.hpp"

using namespace std;

struct SDK_Example {
  string sudoku;
  string solution;
};

vector<SDK_Example> parseSudokuExamples(string file) {
  ifstream input(file, ifstream::in);
  vector<SDK_Example> result;
  string line;
  while (getline(input, line)) {
    //cout<<line<<"\t"<<endl;
    string sudoku(line);
    if (getline(input, line)) {
      //cout<<line<<"\t"<<endl;
      string solution(line);
      SDK_Example entry = {sudoku, solution};
      result.push_back(entry);
    }
  }
  input.close();
  return result;
}

vector<int> parseSudokuData(string sudoku) {
  vector<int> result;
  for (unsigned int i=0; i<sudoku.size(); i++) {
    char charValue = sudoku[i];
    int value = charValue - '0';
    result.push_back(value);
  }
  return result;
}

void printSudokuExamples(vector<SDK_Example> sudokuExamples) {
  for (unsigned int i=0; i<sudokuExamples.size(); i++) {
    cout<<sudokuExamples[i].sudoku<<endl<<sudokuExamples[i].solution<<endl<<endl;
  }
}

int main(){

  vector<SDK_Example> easyExamples = parseSudokuExamples("./tools/easy.txt");
  
  try{
    for (unsigned int i=0; i<easyExamples.size(); i++) {
      vector<int> matrix = parseSudokuData(easyExamples[i].sudoku);
      cout<<"building grid..."<<endl;
      SDK_Grid grid(matrix);
      grid.print();
      cout<<endl;

      cout<<"solving sudoku"<<endl;
      SDK_Solver solver;
      solver.solve(grid);
      if (solver.hasSolutions()) {
      	SDK_Grid solution = solver.popSolution();
      	solution.print();
      	cout<< endl<< solution.toString()<<endl;
      	cout<<easyExamples[i].solution<<endl;
      }
      cout<<"------------------------------------------------------------------"<<endl;
      cout<<endl;
    }
  } catch (const char* e) {
    cout<<"exception: "<<e<<endl;
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
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
    string sudoku(line);
    if (getline(input, line)) {
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

int main(int argc, char** argv){

  string difficulty;
  if (argc != 2) {
    difficulty = "easy";
  } else {
    difficulty = argv[1];
  }
  cout<<difficulty<<endl;
  if (difficulty != "easy" &&
      difficulty != "medium" &&
      difficulty != "hard" &&
      difficulty != "expert") {
    difficulty = "easy";
  }

  string fileName = "./"+difficulty+".txt";

  vector<SDK_Example> examples = parseSudokuExamples(fileName);

  //the following is the hardest sudoku ever and the solver solved it very FAST!!!
  //vector<SDK_Example> examples;
  //SDK_Example example = {"800000000003600000070090200050007000000045700000100030001000068008500010090000400", ""};
  //SDK_Example example = {"880000000000000000000000000000000000000000000000000000000000000000000000000000000", ""};
  //examples.push_back(example);
  
  try{
    for (unsigned int i=0; i<examples.size(); i++) {
      vector<int> matrix = parseSudokuData(examples[i].sudoku);
      cout<<i<<": building grid..."<<endl;
      SDK_Grid originalGrid(matrix);
      originalGrid.print();
      cout<<endl;

      cout<<"solving sudoku"<<endl;
      SDK_Solver solver;
      SDK_Grid copyGrid(originalGrid);
      if (solver.solve(copyGrid)) {
	      cout<<"sudoku solution: "<<endl;
      	SDK_Grid solution = solver.getSolution();
      	solution.print();
      	cout<< endl<< solution.toString()<<endl;
      	cout<<examples[i].solution<<endl;
	      assert(examples[i].solution == solution.toString());
      } else {
	cout<<"sudoku does not have a solution"<<endl;
      }
      cout<<"------------------------------------------------------------------"<<endl;
      cout<<endl;
    }
  } catch (const char* e) {
    cout<<"exception: "<<e<<endl;
  }

  return 0;
}

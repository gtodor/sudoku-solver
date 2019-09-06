#include <rice/Class.hpp>
#include <rice/Array.hpp>
#include <rice/Object.hpp>
#include <vector>
#include <iostream>
#include "../../solver.hpp"
using namespace Rice;


template<>
std::vector<int> from_ruby< std::vector<int> > (Object o)   {
    Array a(o);
    std::vector<int> v;
    for(Array::iterator aI = a.begin(); aI != a.end(); ++aI)
        v.push_back(from_ruby<int>(*aI));
    return v;
}

Array rice_solve(std::vector<int> input){
    if(input.size() != 81){
        return Array(0);
    }
    for(int i = 0; i< 81; i++){
        std::cout<<input[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"beginning"<<std::endl;
    SDK_Grid grid(input);
    std::cout<<"after grid creation"<<std::endl;
    SDK_Solver solver;
    if (solver.solve(grid)) {
        std::cout<<"solver found solution"<<std::endl;
	SDK_Grid solution = solver.getSolution();
        solution.print();
	std::vector<int> data = solution.getData();
        Array result;
        for(int i = 0; i < 81; i++){
            result.push(to_ruby(data[i]));
        }
        return result;
    }
    std::cout<<"solver did not find solution"<<std::endl;
    return Array(0);
}


extern "C"

void Init_sudoku_solver() {
    Class rb = define_class("SudokuSolver")
        .define_method("solve", &rice_solve);
}

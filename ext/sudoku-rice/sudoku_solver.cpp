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
    sdk_grid grid(input);
    std::cout<<"after grid creation"<<std::endl;
    sdk_solver solver(grid);
    std::cout<<"after solver solve"<<std::endl;
    if (solver.solve() == true) {
        std::cout<<"solver found solution"<<std::endl;
        std::vector<int> solution = solver.popSolution();
        std::cout<<"solver solution"<<std::endl;
        Array result;
        for(int i = 0; i < 81; i++){
            result.push(to_ruby(solution[i]));
        }
        return result;
    }
    std::cout<<"solver not found solution"<<std::endl;
    return Array(0);
}


extern "C"

void Init_sudoku_solver() {
    Class rb = define_class("SudokuSolver")
        .define_method("solve", &rice_solve);
}

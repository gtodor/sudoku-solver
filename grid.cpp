#include <iostream>
#include <algorithm>
#include <cassert>
#include "grid.hpp"

using namespace std;

sdk_grid::sdk_grid(vector<int>& from) : data(from) {
    for(int i=0; i<81; i++){
        domains.push_back("123456789");
    }
    for(int i=0; i<81; i++){
        if(data[i] != 0){
            int row = i/9;
            int column = i%9;
            string val(1, '0' + data[i]);
            domains[i] = val;
            if (!propagate(row, column, data[i])){
                throw "sudoku grid not coherent";
            }
        }
    }
}

sdk_grid::sdk_grid(const sdk_grid& from): data(from.data), domains(from.domains) {
}

int findChar(string original, char c){
    int index = -1;
    for(int i=0; i<original.size(); i++){
        if(original[i] == c){
            index = i;
        }
    }
    return index;
}

bool sdk_grid::propagate_column(int column, int value) {
    for(int row=0; row<9; row++){
        string temp1 = domains[row*9 + column];
        char val = '0' + value;
        int eraseIndex = findChar(temp1, val);
        if(eraseIndex >= 0){
            string temp2 = temp1.erase(eraseIndex, 1);
            domains[row*9 + column] = temp2;
        } else {
            return false;
        }
    }
    return true;
}

bool sdk_grid::propagate_row(int row, int value) {
    for(int column=0; column<9; column++){
        string temp1 = domains[row*9 + column];
        char val = '0' + value;
        int eraseIndex = findChar(temp1, val);
        if(eraseIndex >= 0){
            string temp2 = temp1.erase(eraseIndex, 1);
            domains[row*9 + column] = temp2;
        } else {
            return false;
        }
    }
    return true;
}

bool sdk_grid::propagate_sector(int row, int column, int value) {
    int sectors[] = {
        0,  1,  2,  9,  10, 11, 18, 19, 20,
        3,  4,  5,  12, 13, 14, 21, 22, 23,
        6,  7,  8,  15, 16, 17, 24, 25, 26,
        27, 28, 29, 36, 37, 38, 45, 46, 47,
        30, 31, 32, 39, 40, 41, 48, 49, 50,
        33, 34, 35, 42, 43, 44, 51, 52, 53,
        54, 55, 56, 63, 64, 65, 72, 73, 74,
        57, 58, 59, 66, 67, 68, 75, 76, 77,
        60, 61, 62, 69, 70, 71, 78, 79, 80
    };
    int sector_row = row / 3;
    int sector_column = column / 3;
    int sector_index = sector_row * 3 + sector_column;
    for(int i = 0; i < 9; i++){
        string temp1 = domains[sectors[9*sector_index + i]];
        char val = '0' + value;
        int eraseIndex = findChar(temp1, val);
        if(eraseIndex >= 0){
            string temp2 = temp1.erase(remove(temp1.begin(), temp1.end(), val), temp1.end);
            domains[sectors[9*sector_index + i]] = temp2;
        } else {
            return false;
        }
    }
    return true;
}

bool sdk_grid::propagate(int row, int column, int value){
    return propagate_column(column, value) &&
        propagate_row(row, value) &&
        propagate_sector(row, column, value);
}

bool sdk_grid::set(int index, int value){
    data[index] = value;
    string strVal(1, '0' + value);
    domains[index] = strVal;
    int row = index / 9;
    int column = index % 9;
    return propagate(row, column, value);
}

int sdk_grid::get(int index) const{
    return data[index];
}

string sdk_grid::getDomain(int index) const{
    return domains[index];
}

vector<int> sdk_grid::getData() const{
    return vector<int>(data);
}

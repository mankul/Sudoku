#include<iostream>
namespace game{}
using namespace std;
using namespace game;
#ifndef LOADFILE_H
    #include "loadFile.h"
#endif
// #ifndef SOLVER_H
//     #include "solver.h"
// #endif 
#ifndef CONFIG_H
    #include "config.h"
#endif
#ifndef MATRIX_H
    #include "matrix.h"
#endif
#ifndef GRID_H
    #include "grid.h"
#endif
bool solveRow(game::Matrix * , game::GRID , int , int);
bool solverHardCodedCell(game::Matrix * , game::GRID , int , int , int);
void inputGRID(int * matrix[GRIDSIZE]){
    cout<<"input grid"<<endl;
}

bool solverHardCodedCell(game::Matrix * m, game::GRID grid, int rowIndex, int columnIndex, int state){
    bool result = false;
    if(rowIndex < GRIDSIZE){
        result = solveRow(m, grid, rowIndex + 1, columnIndex);
    }
    else if(columnIndex < GRIDSIZE){
        result = solveRow(m, grid, rowIndex % GRIDSIZE , columnIndex + 1);
    }
    else{
        result = true;
    }
    return result;
}

bool solveRow(game::Matrix * m, game::GRID grid, int rowIndex, int columnIndex){
    int state = grid.getState(rowIndex, columnIndex);
    bool result = false;
    int stateCount = 0;
    if(state > 0)
    {
        result = solverHardCodedCell(m, grid, rowIndex, columnIndex, state);
    }
    else{
        while (stateCount < GRIDSIZE )
        {
            state = m->getFiller(grid, rowIndex, columnIndex, state);
            if(state == -1)
                break;
            
            grid.setState(rowIndex, columnIndex, state);
            if(rowIndex < GRIDSIZE)
                result = solveRow(m, grid, rowIndex + 1, columnIndex);
            else if(columnIndex < GRIDSIZE)
                result = solveRow(m, grid, rowIndex%GRIDSIZE, columnIndex + 1);
            else
                result = true;

            if(result)
                return result;
            stateCount += 1;
        }
    }
    return result;
}


void displayGrid(game::GRID grid){
    for(int i = 0 ; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            cout<<grid.getState(i,j)<<"\t";
        }
        cout<<endl;
    }
}



int main(){

    int matrix[GRIDSIZE][GRIDSIZE] ;

    // inputGRID(matrix)
    int initialRow = 0;
    int initialColumn = 0;

    const char * fileName = "sudokuExample.txt";
    readFromFile(fileName);
    // cout<<"enter sudoku puzzle, row wise , number seperated by space"<<endl;
    

    game::Matrix * m;
    game::GRID grid;
    grid.inputToGrid(matrix);
    solveRow(m,grid, 0 , 0);
    return 0;
}
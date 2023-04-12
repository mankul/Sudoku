#include "matrix.h"
#include<iostream>
using namespace game;

bool game::Matrix::getOptRowFiller(GRID grid,int columnIndex, int filler){
    for (int i = 0; i < GRIDSIZE; i++ ){
        if(grid.getState(i, columnIndex) == filler)
            return false;
    return true;
}

bool game::Matrix::getOptColFiller(GRID grid, int rowIndex, int filler){
    for(int i = 0; i < GRIDSIZE;i++)
        if(grid.getState(rowIndex,i)== filler)
            return false;
    return true;
}

bool game::Matrix::getOptGridFiller(GRID grid, int rowIndex, int columnIndex, int filler){
    if( rowIndex%3 == 0 ){
        if( columnIndex %3 == 0)
            return searchInGrid(grid, rowIndex, columnIndex, filler);
        else if(columnIndex %3 == 1)
            return searchInGrid(grid, rowIndex, columnIndex - 1, filler);
        else
            return searchInGrid(grid, rowIndex, columnIndex - 2, filler);
    }
    else if( rowIndex %3 == 1){
        if( columnIndex %3 == 0)
            return searchInGrid(grid, rowIndex - 1, columnIndex, filler);
            
        else if(columnIndex %3 == 1)
            return searchInGrid(grid, rowIndex - 1, columnIndex - 1, filler);
        else
            return searchInGrid(grid, rowIndex - 1, columnIndex - 2, filler);
    }
    else{
        if(columnIndex %3 == 0)
            return searchInGrid(grid, rowIndex - 2, columnIndex, filler);
        else if(columnIndex %3 == 1)
            return searchInGrid(grid, rowIndex - 2, columnIndex - 1, filler);
        else    
            return searchInGrid(grid, rowIndex - 2, columnIndex - 2, filler);
    }
    return true;
}

bool game::Matrix::searchInGrid(GRID grid, int row, int column, int filler){
    for(int i = row; i < row+3; i++)
        for(int j = column; j < column + 3; j++)
            if(grid.getState(i,j) == filler)
                return false;
    return true;
    
}

void game::Matrix::inputGRID(){
    int numberInput;
    for(int i = 0; i < GRIDSIZE; i++)
        for(int j = 0 ; j < GRIDSIZE; j++){
            std::cin>>numberInput;
            grid.setState(i, j, numberInput);
        }
}
int game::Matrix::getFiller(GRID grid, int rowIndex, int columnIndex, int state){
    
    for(int i = state+1; i <= GRIDSIZE; i++){
        bool rowFiller = getOptRowFiller(grid, columnIndex, i);
        bool colFiller = getOptColumnFiller(grid, rowIndex,  i);
        bool gridFiller = getOptGridFiller(grid,rowIndex, columnIndex, i);
        if( rowFiller && colFiller &&  gridFiller)
            break;
        
    }
    if( i >= GRIDSIZE )
        return -1;
    else
        return i;
}



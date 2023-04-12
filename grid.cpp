#include "grid.h"


using namespace game;


GRID::GRID(){
    for(int i = 0 ; i < GRIDSIZE; i++)
        for(int j = 0 ; j <  GRIDSIZE; j++)
            hardCoded[i][j] = 0;
}


int GRID::getState(int rowIndex, int columnIndex){
    return square[rowIndex][columnIndex];
}
void GRID::setState(int rowIndex, int columnIndex, int state){
    square[rowIndex][columnIndex] = state;
}

void GRID::initializeGrid(){
    for(int i = 0; i< GRIDSIZE; i++)
        for(int j = 0; j < GRIDSIZE; j++)
            square[i][j] = hardCoded[i][j];
}
void GRID::ipToGrid(int * gridMatrix[GRIDSIZE]){
    for(int i = 0 ; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            hardCoded[i][j] = gridMatrix[i][j];
            initializeGrid();
        }
    }
}

void GRID::inputToGrid(int gridMatrix[][GRIDSIZE]){
    for(int i = 0 ; i < GRIDSIZE; i++){
        for(int j = 0; j < GRIDSIZE; j++){
            hardCoded[i][j] = gridMatrix[i][j];
            initializeGrid();
        }
    }
}
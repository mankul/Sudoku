#define GRID_H
#ifndef CONFIG_H
    #include"config.h"
#endif
namespace game{
    class GRID
    {
        int square[GRIDSIZE][GRIDSIZE];
        int hardCoded[GRIDSIZE][GRIDSIZE];
        void initializeGrid(); // copy hard coded to square matrix.


        public:
        GRID();
        int getState(int , int );
        void setState(int , int , int );
        void ipToGrid(int * [GRIDSIZE]);
        void inputToGrid(int [][GRIDSIZE]);
    };
}

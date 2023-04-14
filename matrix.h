#define MATRIX_H
#ifndef CONFIG_H
#include "config.h"
#endif
#ifndef GRID_H
#include "grid.h"
#endif
namespace game{
    class Matrix{
        private:
            bool getOptRowFiller(GRID, int, int);
            bool getOptColFiller(GRID, int, int);
            bool getOptGridFiller(GRID, int, int, int);
            bool searchInGrid(GRID, int, int, int);
        public:
            void inputGRID(GRID grid);
            int getFiller(GRID, int , int, int );


    };
}

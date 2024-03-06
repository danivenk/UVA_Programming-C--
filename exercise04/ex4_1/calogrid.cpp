// Dani van Enk, 11823526

// include libraries and headers
#include "calogrid.h"
#include <iostream>

// copy the elements of a grid into an other
CaloGrid::CaloGrid(CaloGrid& other) {

    // check if one is trying to clone this to this
    if (this == &other) {
        return;
    }

    // initialize this with sizes of other
    init(other.get_xsize(), other.get_ysize());

    // copy over the data from other to this
    for (int i = 0; i < _nx; i++) {
        for (int j = 0; j < _ny; j++) {
            *cell(i, j) = *other.cell(i, j);
        }
    }

};

// initialize a grid of size nx by ny
void CaloGrid::init(int nx, int ny) {

    // make sure the grid is at least of size 1x1
    if (nx < 1 || ny < 1) {
        std::cout << "ColGrid::init() Error: make sure the dimensions are at ";
        std::cout << "least larger than 0" << std::endl;
    }

    // set the size parameters
    _nx = nx; _ny = ny;

    // allocate a grid of Calocells
    grid = new CaloCell[nx * ny];
}

// get pointer to a gridcell at (x, y)
CaloCell* CaloGrid::cell(int x, int y) {

    // check if x and y are within the grid range if not return nullptr
    if ((x > _nx && x >= 0) || (y > _nx && y >= 0)) {
        std::cout << "CaloGrid::cell() Error: check if x and y are inside the ";
        std::cout << "range of the Grid" << std::endl;

        return nullptr;
    }

    // return element
    return &grid[x * _nx + y];
}

// get const pointer to gridcell at (x, y)
const CaloCell* CaloGrid::cell(int x, int y) const {

    // return the gridcell pointer
    return CaloGrid::cell(x, y);
}
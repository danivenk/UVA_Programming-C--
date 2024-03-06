// Dani van Enk, 11823526

// used header
#include "calogrid.h"

// copy constructor
CaloGrid::CaloGrid(const CaloGrid &other): _nx(other._nx), _ny(other._ny) {

    // allocate new cell array
    _array = new CaloCell[_nx * _ny];

    // copy data from other to this
    for (int i = 0; i < _nx * _ny; i++) {
        _array[i] = other._array[i];
    }
}

// get cell from position
CaloCell* CaloGrid::cell(int x, int y) {
    
    // make sure the positions are valid
    if (x < 0 || x >= _nx || y < 0 || y >= _ny) return 0;

    return _array + x * _ny + y;
}

// get cell from CellID
CaloCell* CaloGrid::findCellByID(int ID) {

    // loop over the cells in the grid
    for (int i = 0; i < _nx; i++) {
        for (int j = 0; j < _ny; j++) {

            // check cell ID == given ID
            if (cell(i, j)->readoutID() == ID) {
                return cell(i, j);
            }
        }
    }

    return nullptr;
}

// get cell position from CellID
std::tuple<int, int> CaloGrid::findCellPosByID(int ID) {

    // loop over the cells in the grid
    for (int i = 0; i < _nx; i++) {
        for (int j = 0; j < _ny; j++) {

            // check cell ID == given ID
            if (cell(i, j)->readoutID() == ID)
            {
                return std::tuple<int, int>{i, j};
            }
        }
    }

    return std::tuple<int, int>{-1, -1};
}

// clear energies from grid
void CaloGrid::clear() {

    // loop over the celss in the grid
    for (int i = 0; i < _nx; i++) {
        for (int j = 0; j < _ny; j++) {

            // set the energy of the cell to 0
            cell(i, j)->setEnergy(0);
        }
    }
}
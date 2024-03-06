// Dani van Enk, 11823526

#ifndef CALOGRID_H
#define CALOGRID_H
#include "calocell.h"

class CaloGrid {

    public:
        CaloGrid(int nx = 1, int ny = 1) { init(nx, ny); };
        CaloGrid(CaloGrid &other);
        ~CaloGrid() { delete[] grid; };

    private:
        int _nx, _ny;
        CaloCell* grid;

        void init(int nx, int ny);

    public:
        CaloCell* cell(int x, int y);
        const CaloCell* cell(int x, int y) const;

        const int get_xsize() const { return _nx; };
        const int get_ysize() const { return _ny; };
};

#endif
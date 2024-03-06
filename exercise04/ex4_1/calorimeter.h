// Dani van Enk, 11823526

// check if already included
#ifndef CALORIMETER_H
#define COLORIMETER_H

// include headers
#include "calogrid.h"
#include "point.h"

// define a Calori meter in 3d space with a 2d cell grid
class Calorimeter {

    // define constructor and destructor
    public:
        Calorimeter(double x, double y, double z, int nx = 1, int ny = 1) : _grid(nx, ny) {
            init(x, y, z);
        };
        ~Calorimeter() {};

    // define grid, position and init function
    private:
        CaloGrid _grid;
        Point pos;

        void init(double x, double y, double z);

    // getters for the grid and position (const and non const)
    public:
        CaloGrid& grid() { return _grid; };
        const CaloGrid& grid() const { return _grid; };
        Point& position() { return pos; };
        const Point& position() const { return pos; };
};

#endif
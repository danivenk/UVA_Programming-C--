// Dani van Enk, 11823526

// define included libraries/headers
#include "calocell.h"
#include "calogrid.h"
#include "calorimeter.h"
#include "point.h"
#include <iostream>
#include <iomanip>

// declare used functions
void test_CCG_input(CaloGrid &grid, double H);
void test_CCG_inspect(CaloGrid grid);
void test_points();

int main() {

    // create a meter at (1, 1, 1) with a 10x10 grid
    Calorimeter meter(1, 1, 1, 10, 10);

    // get the position of the meter
    const Point pos = meter.position();

    // print out the position
    std::cout << "INITIALIZED METER AT " << pos.get_xpos() << " ";
    std::cout << pos.get_ypos() << " " << pos.get_zpos() << std::endl;

    // copy meter grid
    CaloGrid grid1 = meter.grid();

    // change the values of grid1
    test_CCG_input(grid1, 24.587387);

    // print the cell values of grid1
    std::cout << "Grid1 init" << std::endl;
    test_CCG_inspect(grid1);

    // clone grid1 to grid2
    CaloGrid grid2 = grid1;

    // print the cell values of grid2
    std::cout << "Grid2 after copy Grid1" << std::endl;
    test_CCG_inspect(grid2);

    // change the values of grid2
    test_CCG_input(grid2, 54.417760);

    // print the cell values of grid1 and grid2
    std::cout << "Grid1 after change Grid2" << std::endl;
    test_CCG_inspect(grid1);
    std::cout << "Grid2 after change" << std::endl;
    test_CCG_inspect(grid2);

    // change the values of the meter grid
    test_CCG_input(meter.grid(), 13.6);

    // print the cell values of the meter grid
    std::cout << "Meter grid after those changes" << std::endl;
    test_CCG_inspect(meter.grid());

    // run the points test
    test_points();

    return 0;
}

// change the cell values in the grid
void test_CCG_input(CaloGrid& grid, double H) {

    // init the uid
    int uid = 0;

    // loop over the grid in the x direction
    for (int i = 0; i < grid.get_xsize(); i++) {

        // init n to 1
        int n = 1;

        // loop over the grid in the y direction
        for (int j = 0; j < grid.get_ysize(); j++) {

            // get the cell and set the uid and energy
            CaloCell* cell = grid.cell(i, j);
            cell->set_id(uid++);
            cell->set_energy(-H / (n * n)) ?: cell->set_energy(H / (n * n));

            // increase n by 1
            n++;
        }
    }
}

// print the cell values of the grid
void test_CCG_inspect(CaloGrid grid) {

    // loop over the grid
    for (int i = 0; i < grid.get_xsize(); i++) {
        for (int j = 0; j < grid.get_ysize(); j++) {

            // get the cell and print out the cell values
            CaloCell *cell = grid.cell(i, j);
            std::cout << std::setw(2);
            std::cout << cell->get_id() << " " << cell->get_energy() << "|";
        }

        // don't forget the linend
        std::cout << std::endl;
    }
}

// test points
void test_points() {

    // get a 12x12 grid of points
    int max = 12;
    Point grid[max][max];

    // loop over the grid
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max ; j++) {

            // give x and y the grid position and z the multiple of x and y
            if (i > 0 && i < max - 1 && j > 0 && j < max - 1) {
                grid[i][j].set_pos(i, j, i*j);
            }

            // give x and y the grid position and z 1000
            else {
                grid[i][j].set_xpos(i);
                grid[i][j].set_ypos(j);
                grid[i][j].set_zpos(1000);
            }
        }
    }

    // loop over the grid
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {

            // print xy position and z value
            printf("[%2.0f][%2.0f]: ", grid[i][j].get_xpos(), grid[i][j].get_ypos());
            printf("%4.0f ", grid[i][j].get_zpos());
        }

        // don't forget the linend
        std::cout << std::endl;
    }
}
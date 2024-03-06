// Dani van Enk, 11823526

// used header
#include "calorimeter.h"

// dump the Readout ID of all cells to os
void Calorimeter::dumpReadoutMap(std::ostream &os) {

    // get the side of the grid
    std::tuple<int, int> size = _grid.get_size();

    // print what is going to be print out
    std::cout << "Readout Map" << std::endl;

    // print division line
    std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
    std::cout << std::setfill(' ');

    // loop over the cells in the grid
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {

            // set width to 6 and print cellID
            os << std::setw(6);
            os << _grid.cell(i, j)->readoutID();
        }

        // don't forget the linend
        os << std::endl;
    }
}

// dump the Event to os
void Calorimeter::dumpEvent(std::ostream &os) {

    // print what is going to be print out
    std::cout << "Event Map" << std::endl;

    // print division line
    std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
    std::cout << std::setfill(' ');

    // get the size of the grid
    std::tuple<int, int> size = _grid.get_size();

    // loop over all the cells in the grid
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {

            // set width to 2 end read out the energy of the cell
            os << std::setw(2);
            double energy = _grid.cell(i, j)->energy();

            // put a . for E < .5, x for E in [.5, 2] & X for E > 2 
            if (energy < .5) {
                os << ".";
            } else if (energy >= .5 && energy <= 2) {
                os << "x";
            } else {
                os << "X";
            }
        }

        // don't forget the linend
        os << std::endl;
    }
}

// dump the Readout ID of all cells to os
void Calorimeter::dumpClusterMap(std::ostream &os) {

    // print what is going to be print out
    std::cout << "Cluster Map" << std::endl;

    // print division line
    std::cout << std::setfill('#') << std::setw(79) << "#" << std::endl;
    std::cout << std::setfill(' ');

    // get the side of the grid
    std::tuple<int, int> size = _grid.get_size();

    // loop over the cells in the grid
    for (int i = 0; i < std::get<0>(size); i++) {
        for (int j = 0; j < std::get<1>(size); j++) {

            // set width to 2 and print cellID
            os << std::setw(2);
            os << _grid.cell(i, j)->clusterID();
        }

        // don't forget the linend
        os << std::endl;
    }
}
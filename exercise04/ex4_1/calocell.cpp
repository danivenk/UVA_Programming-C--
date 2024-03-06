// Dani van Enk, 11823526

// include headers
#include "calocell.h"

// initialize a cell with an id and energy
void CaloCell::init(double energy, int id) {
    _energy = energy;
    _id = id;
}

// set the energy of the cell
bool CaloCell::set_energy(double energy) {
    if (energy < 0) { return false; }

    _energy = energy;

    return true;
}

// set the id of the cell
bool CaloCell::set_id(int id) {
    if (id < 0) { return false; }

    _id = id;
    
    return true;
}
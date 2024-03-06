// Dani van Enk, 11823526

// include headers
#include "calorimeter.h"
#include "calogrid.h"

// initialize Calorimeter at position x, y, z
void Calorimeter::init(double x, double y, double z) {
    pos.set_pos(x, y, z);
}
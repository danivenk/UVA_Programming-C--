// Dani van Enk, 11823526

// include point header
#include "point.h"

// initialize point with x, y, z values
void Point::init(double x, double y, double z) {
    _x = x; _y = y; _z = z;
}

// set x position
bool Point::set_xpos(double value) {
    _x = value;

    return _x == value;
}

// set y position
bool Point::set_ypos(double value) {
    _y = value;

    return _y == value;
}

// set z position
bool Point::set_zpos(double value) {
    _z = value;

    return _z == value;
}

// set x, y, z position
bool Point::set_pos(double x, double y, double z) {
    _x = x; _y = y; _z = z;

    return _x == x && _y == y && _z == z;
}
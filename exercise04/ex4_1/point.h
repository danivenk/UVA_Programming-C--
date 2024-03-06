// Dani van Enk, 11823526

// check if already included
#ifndef POINT_H
#define POINT_H

// defines a point in 3d space
class Point {

    // constructor and destructor definition
    public:
        Point(double x = 0, double y = 0, double z = 0) { init(x, y, z); };
        ~Point() {};

    // define x, y, z coordinates and init function
    private:
        double _x, _y, _z;

        void init(double x, double y, double z);

    // x, y, z getters/setters and set position definition
    public:
        double get_xpos() const { return _x; };
        bool set_xpos(double value);
        double get_ypos() const { return _y; };
        bool set_ypos(double value);
        double get_zpos() const { return _z; };
        bool set_zpos(double value);

        bool set_pos(double x, double y, double z);
};

#endif
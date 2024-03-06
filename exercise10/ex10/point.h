// Dani van Enk, 11823526

// make sure point is only included once
#ifndef POINT_H
#define POINT_H

// define a 3d point
class Point {
public:

	// 3d point constructor
	Point(double x = 0, double y = 0, double z = 0) : _x(x), _y(y), _z(z) {};

	// x/y/z accessors
	double x() const { return _x; };
	double y() const { return _y; };
	double z() const { return _z; };
	
	// x/y/z setters
	void setX(double x) { _x = x; };
	void setY(double y) { _y = y; };
	void setZ(double z) { _z = z; };

	// x/y/z instant setter
	void set(double x, double y, double z) { _x = x; _y = y; _z = z; };

private:

	// declare the axis positions
	double _x, _y, _z;

};

#endif 

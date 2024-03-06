// Dani van Enk, 11823526

// make sure calorimeter is only included once
#ifndef CALORIMETER_H
#define CALORIMETER_H

// include used headers and library
#include "calogrid.h"
#include "point.h"
#include <iomanip>

// define a calorimeter
class Calorimeter {
public:

	// constructor from size and position
	Calorimeter(int sizex, int sizey, Point position=Point(0, 0, 0)) : 
		_grid(sizex,sizey), _pos(position) {};

	// accessers and setters for the grid and position
	CaloGrid& grid() { return _grid; };
	const CaloGrid& grid() const { return _grid; };
	Point& position() { return _pos; };
	const Point& position() const { return _pos; };

private:

	// define the grid and position
	CaloGrid _grid;
	Point _pos;

public:
	
	// dump readoutID of the cells or an event
	void dumpReadoutMap(std::ostream& os = std::cout);
	void dumpEvent(std::ostream &os = std::cout);
	void dumpClusterMap(std::ostream &os = std::cout);
};

#endif 

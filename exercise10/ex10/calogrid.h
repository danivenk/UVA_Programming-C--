// Dani van Enk, 11823526

// make sure calogrid is only included once
#ifndef CALOGRID_H
#define CALOGRID_H

// included header and libraries
#include "calocell.h"
#include <iostream>
#include <tuple>

// define a grid in a calometer
class CaloGrid {
public:

	// calogrid constructor from it's size
	CaloGrid(int size_x, int size_y) : _nx(size_x), _ny(size_y) {
		_array = new CaloCell[_nx * _ny];
	};

	// copy constructor
	CaloGrid(const CaloGrid& other);

	// destroctor (delete associated data)
	~CaloGrid() {
		delete[] _array;
	};
	
	// access const cell in grid
	const CaloCell* cell(int x, int y) const { 
		return const_cast<CaloGrid*>(this)->cell(x,y); 
	};
	
	// find cell by position or ID
	CaloCell* cell(int x, int y);
	CaloCell* findCellByID(int ID);

	// find cell position by ID
	std::tuple<int, int> findCellPosByID(int ID);

	// get size of grid
	std::tuple<int, int> get_size() { return std::tuple<int, int>{_nx, _ny}; };

	// clear the detected energies in the grid
	void clear();

private:

	// define the grid size and a cell array
	int _nx;
	int _ny;
	CaloCell *_array;
};

#endif 

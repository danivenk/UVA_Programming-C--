// Dani van Enk, 11823526

// used library
#include <iostream>

// make sure array is only included once
#ifndef ARRAY_HH
#define ARRAY_HH

class Array {
	public:

		// constructor
		Array(int size) : _size(0), _arr(0) {
			// call resize to initialize oneself
			resize(size);
		}

		// copy constructor
		Array(const Array& other) : _size(other._size) {
			
			// allocate an array of size other
			_arr = new double[other._size];

			// copy elements
			for (int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}
		}

		// destructor
		~Array() {
			delete[] _arr;
		}

		// copy an array to this
		Array& operator=(const Array& other) 
		{
			// make sure other is not this
			if (&other==this) return *this;

			// resize this to the size of other
			if (_size != other._size) {
				resize(other._size);
			}

			// copy over the contents
			for (int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}
		}

		// return the value of the array and throw error if invalid index
		double& operator[](int index) {
			if (index >= _size || index < 0) {
				ArrayOutOfBounds err(index);
				throw err;
			}
			return _arr[index];
		}

		// return the const value of the array and throw error if invalid index
		const double& operator[](int index) const {
			if (index >= _size || index < 0) {
				ArrayOutOfBounds err(index);
				throw err;
			}
			return _arr[index];
		}

		// get the size of the array
		int size() const { return _size; }

		// resize the array
		void resize(int newSize) {
			// allocate new array
			double* newArr = new double[newSize];

			// copy elements
			for (int i = 0; i < _size; i++) {
				newArr[i] = _arr[i];
			}

			// delete old array and install new one
			if (_arr) {
				delete[] _arr;
			}

			// set the new array and size
			_size = newSize;
			_arr = newArr;
		}

		// error helper class
		class ArrayOutOfBounds {

			// constructor and get error index
			public:
				ArrayOutOfBounds(int index) : _index(index){};
				int index() const { return _index; }

			// declare error index
			private:
				int _index;
		};

	// declare the size and contents of the array
	private:
		int _size;
		double* _arr;
};

// return the error message to the os stream using the streaming operator
std::ostream &operator<<(std::ostream &os, const Array::ArrayOutOfBounds &m) {
	return (os << "Array index is out of bounds");
}

#endif

// Dani van Enk, 11823526

// make sure the header is only included once
#ifndef ARRAY_H
#define ARRAY_H

// define a template class for an array
template <class T>
class Array {
	public:

		// construct an array of given size
		Array(int size) : _size(0), _arr(0) {
			// Call resize to initialize oneself
			resize(size);
		};

		// copy an array from a different array
		Array(const Array& other) : _size(other._size) {
			_arr = new T[other._size];

			// Copy elements
			for (int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}
		}

		// delete the data associated with this array
		~Array() { delete[] _arr; };

	private:

		// initialize size and pointer to array
		int _size;
		T* _arr;

	public:

		// assignment operator from array to array
		Array& operator=(const Array& other) {

			// return this when other is equal to this
			if (&other == this) {
				return *this;
			}

			// if the sizes don't match make them match
			if (_size != other._size) {
				resize(other._size);
			}

			// copy the data over
			for (int i = 0; i < _size; i++) {
				_arr[i] = other._arr[i];
			}

			return *this;
		};

		// index operator of array
		/*
		* was not safe for accessing out of bounds, with resize it is
		*/
		T& operator[](int index) {

			// if index is out of bounds, increase size so in bounds
			if (index > _size - 1) {
				resize(index + 1);
			}

			// return the value at the asked index
			return _arr[index];
		};

		// index constant operator of array
		/*
		* still not safe, but can not fix this because it is
		* 	a constant retrieval of the value and it can't change
		*  the object
		*/
		const T& operator[](int index) const {
			return _arr[index];
		};

		// return size of array
		int size() const { return _size; };

		// change size of array
		void resize(int newSize) {

			// Allocate new array
			T *newArr = new T[newSize];

			// Copy elements
			for (int i = 0; i < _size; i++) {
				newArr[i] = _arr[i];
			}

			// Delete old array and install new one
			if (_arr) {
				delete[] _arr;
			}
			
			// set the new parameters of the array
			_size = newSize;
			_arr = newArr;
		};
};

#endif

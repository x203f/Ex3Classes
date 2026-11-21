#include "Vector.h"


// HELPER FUNCTION: this function will add the resize factor to capacity and allocate another arr.
void Vector::_resizeFactorIncrease() {
	this->_capacity += this->_resizeFactor;

	int* newElements = new int[this->_capacity];
		
	// copy the elements
	for (int i = 0; i < this->_size; i++) { // if this.size is 0, it doesnt enter
		newElements[i] = this->_elements[i];
	}

	// free the old array
	delete[] _elements;

	// set the new array
	this->_elements = newElements;
		
		


}


	/*
		This constructor will take n as items and build a new vector
		n: the size of items
	*/
Vector::Vector(int n) {

	n = (n < 2) ? 2 : n; // if the sizeis less than 2, set n to 2. otherwise n
		// initialize vector, set capacity, resize factor to n as stated in the assignment
	this->_capacity = n;
	this->_size = 0;
	this->_resizeFactor = n;
	this->_elements = new int[n];

}

Vector::~Vector() {
	this->_capacity = 0;
	this->_size = 0;
	this->_resizeFactor = 0;
	delete[] this->_elements;
}
// not gonna explain that it just getss all the attributes of vector.
int Vector::size() const { return this->_size; }

int Vector::capacity() const { return this->_capacity; } //return capacity of vector
int Vector::resizeFactor() const { return this->_resizeFactor; } //return vector's resizeFactor

	
bool Vector::empty() const { return this->_elements == nullptr || this->_size == 0; } //returns true if size = 0 or element is snullptr

void Vector::push_back(const int& val) {

	/*
		This function will add val to the elements. if needed, itll resize the array.
		val: value to add
	*/


	if (this->_size + 1 > this->_capacity) 
		this->_resizeFactorIncrease();

	this->_elements[this->_size++] = val;
}

int Vector::pop_back() {
	/*
		this function will remove an element and return it.
		if the vector is empty, print a message and return VECTOR_EMPTY_ERROR
	*/

	// if its empty
	if (this->empty()) {

		std::cerr << "Error: pop from empty" << std::endl;

		return VECTOR_EMPTY_ERROR;
	}

	// access the last element
	int lastElem = this->_elements[--this->_size];

	this->_elements[this->_size] = 0;

	return lastElem;

}

// this function will allocate enough space to store the (n)th digit.
// n: the index destination
void Vector::reserve(const int n) {
	if (n <= this->_capacity) return; // dont run it. no resize needed

	int diff = (n - this->_capacity);
	int resizeTimes = (diff + _resizeFactor - 1) / _resizeFactor;

		// im too lazy to put more if so i decided to make it in one line

		// if n is 23 and resizeFactor is 5 and capacity is 10

		// diff = 23 - 10 = 13

		// resizeTimes = (13 + 5 - 1) = 17 - 1 = 16 / resizefactor = 3. 
		

	for (int i = 0; i < resizeTimes; i++) this->_resizeFactorIncrease();
}


// function to set all the values of vector to val
// val: a number to set all values.
void Vector::assign(const int val) {
	if (this->empty()) return; // check if its empty (cuz if its nullptr we will get an access violation)

	// assign
	for (int i = 0; i < this->_size; i++) {
		this->_elements[i] = val;
	}
}


// same function but when adding itll write val to it.
// n: index dest
// val: value to set it in
void Vector::resize(int n, const int& val) {
	if (n < 0) return;
	if (n >= this->_size) {
		this->reserve(n);
	}
	// assign all values from size to the n
	for (int i = this->_size; i < n; i++) {
		this->_elements[i] = val;
	}

	
	this->_size = n;
}

// function to resize the vector to match n and set the size to n
// n: index dest
void Vector::resize(int n) {
	this->resize(n, PLACEHOLDER_VALUE);
}

// this is a copying constructor. itll get other and copy the contents to there.
// other: the vector to copy from
Vector::Vector(const Vector& other) {

	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	
	this->_elements = new int[other._capacity];

	for (int i = 0; i < other._size; i++) {
		this->_elements[i] = other._elements[i];
	}

}

// operator =. will copy all the contents from other.
// other: the assigned vector from (=).
Vector& Vector::operator=(const Vector& other) {
	if (this == &other) return *this; // if the objects are same, no point in copying.
	
	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;

	// delete to save up space and make new
	delete[] this->_elements;

	this->_elements = new int[other._capacity];

	for (int i = 0; i < other._size; i++) {
		this->_elements[i] = other._elements[i];
	}
	
	// return itself
	return *this;
}
// this operator [n] will access the [n] element in the array.
// n: the index passed into brackets
int& Vector::operator[](int n) const {
	if (n >= this->_size || n < 0) {
		std::cerr << "Accessing an invalid index." << std::endl;
		return this->_elements[0];
	} 

	if (this->empty()) {
		std::cerr << "Accessing an empty index." << std::endl;
		return this->_elements[0];
	}

	return this->_elements[n];

}
// a friend function is a function that can access private attributes and use them.
// it is NOT a member function.

// this function will return a string of the vector so it can be printed.
std::ostream& operator<<(std::ostream& os, const Vector& v) {

	os << "Vector info:\nCapacity is " << v._capacity << "\nSize is " << v._size << "\ndata is ";

	// format: [1,2,3,4,5]
	os << "{"; // add a [

	for (int i = 0; i < v._size - 1; i++) {
		os << v[i];

		os << ",";
	}

	os << v[v._size - 1] << "}\n";

	return os; // it expects std::ostream to be returned.

}

// this function on operator + will add to v1 the values of v2 on the same indexes.
Vector& Vector::operator+=(const Vector& other) {

	for (int i = 0; i < this->_size && i < other._size; i++) {
		this->_elements[i] += other._elements[i];
	}

	return *this;
}

// this function on operator - will subtract from v1 the values of v2 on the same indexes.

Vector& Vector::operator-=(const Vector& other) {
	for (int i = 0; i < this->_size && i < other._size; i++) {
		this->_elements[i] -= other._elements[i];
	}

	return *this;
}

// this function will just add to v1 and v2 the values on their indexes and save it to v3.
Vector Vector::operator+(const Vector& other) const {

	// make a new vector
	Vector v3(*this);
	// use the previous += we defined
	v3 += other;

	return v3;
}
// this function will just add to v1 and v2 the values on their indexes and save it to v3.
Vector Vector::operator-(const Vector& other) const {

	// make a new vector
	Vector v3(*this);

	// use the previous -= we defined
	v3 -= other;

	return v3;
}

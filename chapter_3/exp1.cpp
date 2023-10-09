#include <iostream>
#include <algorithm>


class MyArray {

private:
	double* elem;
	int size;

public:
	MyArray(std::initializer_list<double> lst)
		: elem{new double[lst.size()]}, size(lst.size()) { 
		std::copy(lst.begin(), lst.end(), elem);
	}
	MyArray(int s)
		: elem{new double[s]}, size{s} { 
	}

	~MyArray() {
		delete[] elem;
	}


	void printArray() {
		for (int i = 0; i < size; i++) {
			std::cout << elem[i] << std::endl;
		}
	}

};



int main() {

	// Using class MyArray
	MyArray arr = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	arr.printArray();

	return 0;

}
#include <iostream>
#include <string>


template <typename T>
class MyArray {

private:
	T* elem;
	int size;

public:
	MyArray(std::initializer_list<T> lst)
		: elem{ new T[lst.size()] }, size(lst.size()) {
		std::copy(lst.begin(), lst.end(), elem);
	}
	MyArray(int s)
		: elem{ new T[s] }, size{ s } {
	}
	~MyArray() {
		delete[] elem;
	}

	T& operator[](int id) {
		if (id < size - 1 && id >= 0)
			return elem[id];
		else 
			throw std::out_of_range("Out of range for MyArray");
	}
	const T& operator[](int id) const{
		if (id < size - 1 && id >= 0)
			return elem[id];
		else
			throw std::out_of_range("Out of range for MyArray");
	}
	
	// Can create begin() and end() methods instead of creating 
	// begin() and end() functions
	T* begin() {
		return &elem[0];
	}
	T* end() {
		return this->begin() + size;
	}

	void printArray() {
		for (int i = 0; i < size; i++) {
			std::cout << elem[i] << std::endl;
		}
	}
	int getSize() {
		return size;
	}

};

// template <typename T>
// T* begin(MyArray<T>& x) {
// 	return &x[0];
// }

// template <typename T>
// T* end(MyArray<T>& x) {
// 	return begin(x) + x.getSize();
// }


int main() {

	MyArray<int> maInt = { 1, 2, 3, 4, 5 };
	MyArray<double> maDouble = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	MyArray<std::string> maString = { "abc", "def", "ghi", "jkl", "mno"};

	for (auto elem : maInt) std::cout << elem << ' ';
	std::cout << std::endl;
	for (auto elem : maDouble) std::cout << elem << ' ';
	std::cout << std::endl;
	for (auto elem : maString) std::cout << elem << ' ';
	std::cout << std::endl;

	return 0;

}
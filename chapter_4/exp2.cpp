#include <iostream>
#include <vector>


template <typename T>
class Vec : public std::vector<T> {
public:
	using std::vector<T>::vector;

	T& operator[](int id) {
		return std::vector<T>::at(id);
	}
	const T& operator[](int id) const {
		return std::vector<T>::at(id);
	}

};

template <typename T>
void print(const std::vector<T>& vec) {
	for (const auto& x : vec)
		std::cout << x << ' ';
	std::cout << std::endl;
}


int main() {

	std::cout << "Start values in vector:\n";
	std::vector<int> v = { 1, 2, 3, 4, 5 };
	print(v);

	std::cout << "\nPush_back 9, 8, 7, 6:\n";
	v.push_back(9);
	v.push_back(8);
	v.push_back(7);
	v.push_back(6);
	print(v); std::cout << std::endl;

	// TEST VEC CLASS
	Vec<double> myVec = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	
	try {
		myVec[1] = 0.0; print(myVec);
		myVec[101] = 0.0; print(myVec);
	}
	catch (std::out_of_range) {
		std::cerr << "Out of range error.\n";
	}
	catch (...) {
		std::cerr << "Unexpected error.\n";
	}

	return 0;

}
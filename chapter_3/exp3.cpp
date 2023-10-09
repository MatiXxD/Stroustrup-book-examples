#include <iostream>


class MyArray {

private:
	double* elem;
	int size;

public:
	MyArray(std::initializer_list<double> lst)
		: elem{ new double[lst.size()] }, size(lst.size()) {
		std::copy(lst.begin(), lst.end(), elem);
	}
	MyArray(int s)
		: elem{ new double[s] }, size{ s } {
	}
	~MyArray() {
		delete[] elem;
	}

	double& operator[](int id) {
		if (id < size && id >= 0)
			return elem[id];
        throw std::out_of_range("Out of range for MyArray");
	}
	const double& operator[](int id) const{
		if (id < size && id >= 0)
			return elem[id];
        throw std::out_of_range("Out of range for MyArray");
	}

	MyArray(MyArray& ma)
		: elem{new double[ma.size]}, size{ma.size} {
		for (int i = 0; i < size; i++)
			elem[i] = ma.elem[i];
	}
	MyArray& operator=(MyArray& ma) {
		double* temp = new double[ma.size];
		for (int i = 0; i < ma.size; i++)
			temp[i] = ma.elem[i];
		size = ma.size;
		delete[] elem; elem = temp;
		return *this;
	}

	MyArray(MyArray&& ma)
		: elem{ma.elem}, size{ma.size} {
		ma.elem = nullptr;
		ma.size = 0;
	}
	MyArray& operator=(MyArray&& ma) {
		elem = ma.elem;
		size = ma.size;
		ma.elem = nullptr;
		ma.size = 0;
		return *this;
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


int main() {

	MyArray ma1{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	MyArray ma2(ma1);

	std::cout << "Copy constructor\n";
	std::cout << "ma1:\n"; ma1.printArray(); std::cout << std::endl;
	std::cout << "ma2:\n"; ma2.printArray(); std::cout << std::endl;


	std::cout << "\nOperator =\n";
	MyArray ma3{ 9.9, 8.8, 7.7, 6.6, 5.5 };
	std::cout << "ma3 before copy:\n"; ma3.printArray(); std::cout << std::endl;
	ma3 = ma1;
	std::cout << "ma3 after copy:\n"; ma3.printArray(); std::cout << std::endl;

	MyArray ma4{ 9.9, 8.8, 7.7, 6.6, 5.5 };
	std::cout << "Move with operator=\n";
	std::cout << "ma4:\n"; ma4.printArray(); std::cout 
		<< "SIZE=" << ma4.getSize() << std::endl;
	std::cout << "ma3:\n"; ma3.printArray(); std::cout 
		<< "SIZE=" << ma3.getSize() << std::endl;
	ma3 = std::move(ma4);
	std::cout << "ma4:\n"; ma4.printArray(); std::cout
		<< "SIZE=" << ma4.getSize() << std::endl;
	std::cout << "ma3:\n"; ma3.printArray(); std::cout
		<< "SIZE=" << ma3.getSize() << std::endl;

	return 0;

}
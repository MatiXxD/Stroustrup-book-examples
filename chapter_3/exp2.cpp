#include <iostream>
#include <vector>
#include <list>



///////////////////////////////////////////////////////
class Container {

public:
	virtual double& operator[](int) = 0;
	virtual int size() const = 0;
	virtual ~Container() {}

};

class VectorContainer : public Container {

private:
	std::vector<double> vec;

public:
	VectorContainer() {
	}
	VectorContainer(int s)
		: vec(s) { 
	}
	VectorContainer(std::initializer_list<double> lst)
		: vec{lst} { 
	}

	~VectorContainer() {
	}

	int size() const {
		return vec.size();
	}

	double& operator[](int id) {
		return vec[id];
	}

};

class ListContainer : public Container {

private:
	std::list<double> lst;

public:
	ListContainer() {
	}
	ListContainer(int s)
		: lst{ double(s) } {
	}
	ListContainer(std::initializer_list<double> li)
		: lst{li} {
	}

	~ListContainer() {
	}

	int size() const {
		return lst.size();
	}

	double& operator[](int);

};

double& ListContainer::operator[](int id) {

	for (auto& elem : lst) {
		if (id == 0) return elem;
		id--;
	}
	throw std::out_of_range("List container");

}
///////////////////////////////////////////////////////


void use(Container& container) {

	const int size = container.size();
	for (int i = 0; i < size; i++) {
		std::cout << container[i] << std::endl;
	}

}



int main() {

	VectorContainer vec = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	ListContainer lst = { 9.9, 8.8, 7.7, 6.6, 5.5 };

	use(vec); std::cout << std::endl;
	use(lst); std::cout << std::endl;

	return 0;

}
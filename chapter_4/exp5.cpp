#include <iostream>
#include <vector>
#include <algorithm>


namespace Estd {
	using namespace std;

	template <class C>
	void sort(C& c) {
		sort(c.begin(), c.end());
	}

}


template <typename T>
void print(const std::vector<T>& vec) {
	for (const T& val : vec)
		std::cout << val << ' ';
	std::cout << std::endl;
}


int main() {

	std::vector<int> vec{ 1, 10, 3, 34, 12, 2, 11, 54, 191, 3214, 13, 145, 19, 8, 81, 1 };
	
	std::cout << "Before sort():\n"; print(vec);
	Estd::sort(vec);
	std::cout << "\nAfter sort():\n"; print(vec);

	return 0;

}
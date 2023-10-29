#include <iostream>
#include <vector>
#include <thread>


void f(std::vector<int>& vec) {
	for (auto& elem : vec) elem = elem * elem;
}

class F {
private:
	std::vector<int>& vec;
public:
	F(std::vector<int>& vecIn)
		: vec{vecIn} { 
	}
	void operator()() {
		for (auto& elem : vec) elem = elem * elem;
	}
};


void printVec(const std::vector<int>& vec) {
	for (int val : vec) std::cout << val << ' ';
	std::cout << std::endl;
}


int main() {

	std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> vec2 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	printVec(vec1); printVec(vec2);

	std::thread t1{ f, std::ref(vec1) };
	std::thread t2{ F{std::ref(vec2)} };
	t1.join();
	t2.join();

	std::cout << std::endl;
	printVec(vec1); printVec(vec2);

	return 0;

}
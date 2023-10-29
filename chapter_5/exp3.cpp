#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


void f(const std::vector<int>& vec, double* res) {
	*res = 0;
	for (auto elem : vec) *res += elem;
}

class F {
private:
	const std::vector<int>& vec;
	double* res;
public:
	F(std::vector<int>& vecIn, double* resIn)
		: vec{vecIn}, res(resIn) { 
	}
	void operator()() {
		for (auto elem : vec) {
			*res = 0;
			for (auto elem : vec) *res += elem;
		}
	}
};


void printVec(const std::vector<int>& vec) {
	for (int val : vec) std::cout << val << ' ';
	std::cout << std::endl;
}


int main() {

	auto time0 = std::chrono::high_resolution_clock::now();

	std::vector<int> vec1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> vec2 = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };

	double res1, res2;
	std::thread t1{ f, std::ref(vec1), &res1 };
	std::thread t2{ F{std::ref(vec2), &res2} };
	t1.join();
	t2.join();

	std::cout << "Vector:\n"; printVec(vec1);
	std::cout << "Sum: " << res1 << "\n\n";

	std::cout << "Vector:\n"; printVec(vec2);
	std::cout << "Sum: " << res2 << "\n\n";

	auto time1 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(time1 - time0).count() << " msec\n";

	return 0;

}
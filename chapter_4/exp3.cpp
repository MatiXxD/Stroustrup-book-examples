#include <iostream>
#include <string>
#include <vector>
#include <list>


template <typename C, typename V>
std::vector<typename C::iterator> findAll(C& c, V v) {

	std::vector<typename C::iterator> res;
	for (auto val = c.begin() ; val != c.end(); val++)
		if (*val == v) res.push_back(val);

	return res;

}


int main() {

	std::string m{ "Mary had a little lamp" };
	auto strIters = findAll(m, 'a');
	for (auto val : strIters)
		std::cout << val - m.begin() << ' ';
	std::cout << std::endl;

	std::list<double> ld{ 1.1, 2.2, 3.3, 4.4 };
	auto lstIters = findAll(ld, 1.1);
	for (auto val : lstIters)
		std::cout << "find" << ' ';
	std::cout << std::endl;

	std::vector<std::string> vs{ "red", "blue", "green", "green", "orange", "green" };
	auto iters = findAll(vs, "green");
	for (auto val : iters)
		std::cout << val - vs.begin() << ' ';
	std::cout << std::endl;

	return 0;

}
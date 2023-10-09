#include <iostream>
#include <string>
#include <vector>
#include <list>

template <typename T>
class LessThan {

private:
	const T value;

public:
	LessThan(const T& v) : value(v) { }
	bool operator()(const T& v) {
		return v < value;
	}
};


void testLessThan() {
	LessThan<int> lsi(42);
	std::cout << lsi(1) << ' ' << lsi(100) << std::endl;
	LessThan<std::string> lss("Backus");
	std::cout << lss("Aackus") << ' ' << lss("Cackus") << std::endl;
}

template <typename C, typename P>
int count(const C& container, P predicat) {
	int count = 0;
	for (const auto& x : container)
		if (predicat(x)) count++;
	return count;
}


int main() {

	testLessThan();

	double value = 5.0;
	std::vector<double> vec = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	std::string str = "abc";
	std::list<std::string> lst = { "aaa", "bac", "bbb", "abd", "aba", "aca", "afdas" };

	std::cout << "\nUSING FUNCTIONAL OBJECT:\n";
	std::cout << "Count elem in vector less than " << value
		<< " : " << count(vec, LessThan<double>(value)) << std::endl;
	std::cout << "Count elem in list less than " << str
		<< " : " << count(lst, LessThan<std::string>(str)) << std::endl;

	std::cout << "\nUSING LAMBDA:\n";
	std::cout << "Count elem in vector less than " << value << " : " 
		<< count(vec, [value](int a) {return a < value; }) 
		<< std::endl;
	std::cout << "Count elem in list less than " << str << " : "
		<< count(lst, [str](const std::string& s) {return s < str; }) 
		<< std::endl;

	return 0;

}
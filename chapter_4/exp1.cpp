#include <iostream>

struct Entry {
	std::string name;
	int number;
};

std::ostream& operator << (std::ostream& os, const Entry& e) {
	std::cout << "{\"" << e.name << "\", " << e.number << '}';
	return os;
}

std::istream& operator >> (std::istream& is, Entry& e) {

	char ch, ch2;
	if (is >> ch && ch == '{' && is >> ch2 && ch2 == '"') {
		std::string name;
		while (is.get(ch) && ch != '"')
			name += ch;

		if (is >> ch && ch == ',') {
			int number;
			if (is >> number >> ch && ch == '}') {
				e = { name, number };
				return is;
			}
		}
	}

	is.setstate(std::ios_base::failbit);
	return is;

}


int main() {

	Entry e1 = { "John Marwood Cleese", 123456 };
	std::cout << e1 << std::endl;

	Entry e2;
	std::cin >> e2;
	std::cout << e2 << std::endl;

	for (Entry e; std::cin >> e;)
		std::cout << e << std::endl;

	return 0;

}
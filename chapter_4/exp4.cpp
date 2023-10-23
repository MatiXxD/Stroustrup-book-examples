#include <iostream>
#include <iterator>
#include <fstream>
#include <set>


int main() {

	std::string in, out;
	std::cout << "Enter input and output files:\n";
	std::cin >> in >> out;

	std::ofstream fout(out);
	std::ifstream fin(in);

	std::set<std::string> st{ std::istream_iterator<std::string>(fin), std::istream_iterator<std::string>() };
	std::copy(st.begin(), st.end(), std::ostream_iterator<std::string>(fout, "\n"));

	return !fin.eof() | !fout;

}
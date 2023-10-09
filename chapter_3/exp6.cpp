#include <iostream>


template <typename T>
void g(T val) {
	std::cout << val << ' ';
}

void f(){ }

template <typename T, typename... Tail>
void f(T head, Tail... tail) {
	g(head);
	f(tail...);
}


int main() {

	f(1, "test", 1.2, '!'); std::cout << std::endl;

	return 0;

}
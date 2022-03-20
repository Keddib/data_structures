#include "LinkedList.hpp"
#include <iostream>

int main() {
	List<std::string> l;
	l.addToHead("hello");
	l.addToTail("hello2");
	std::cout << l.length() << '\n';
	l.deleleNode("test");

	std::cout << l.isInList("hello") << '\n';
	return 0;
}

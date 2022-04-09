#include "queueArrayImplementation.hpp"

#include <iostream>

int main() {

	queue<int> que;

	for(int i = 0; i < 10; i++)
		que.enqueue(i);
	que.print();
	std::cout << que.isEmpty() << '\n';
	std::cout << que.frontt() << '\n';

}

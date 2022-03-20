/*
	this test show a use case of STACK data_structure
*/


#include <iostream>
#include <stack>


void delimiterMatching(const std::string &Line) {
	std::stack<char> st1;
	size_t i; // index
	while (Line[i]) {
		if (Line[i] == '(' || Line[i] == '[' || Line[i] == '{')
			st1.push(Line[i]);
		else if (Line[i] == ')' || Line[i] == ']' || Line[i] == '}')
			if (Line[i] != st1.top()) {
				std::cout << "failed\n"; return ;
			}
			else {
				st1.pop(); continue;
			}
		else
			i++;
	}
}

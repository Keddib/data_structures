/*
** One application of the stack is in matching delimiters in a program. this is an important example because
** delimiter matching is part of any compiler: No program considered correct if the delimiters are mismatched.
** This program show case the use of stack to preform delimiter matching check
** for parebtheses "(" and ")", square brackets "[" and "]" and curly brackets "{" and "}".
*/


#include <iostream>
#include "stack.hpp"

bool isMatch(char x, char y) {
	if (x == '(' && y == ')')
		return true;
	else if (x == '[' && y == ']')
		return true;
	else if (x == '{' && y == '}')
		return true;
	return false;
}


void delimiterMatching(const std::string &Line) {
	stack<char> st1;
	size_t i = 0; // index
	while (Line[i]) {
		if (Line[i] == '(' || Line[i] == '[' || Line[i] == '{')
			st1.push(Line[i]);
		if (Line[i] == ')' || Line[i] == ']' || Line[i] == '}') {
			if (isMatch(st1.top(), Line[i])) {
				st1.pop();
				i++;
				continue;
			}
			else {
				std::cout << "failed\n";
				return ;
			}
		}
		i++;
	}
	if (st1.empty())
		std::cout << "success\n";
	else std::cout << "failed\n";
}


int main(int argc, char **argv) {
	if (argc != 2)
		return 1;

	delimiterMatching(argv[1]);

	return 0;
}

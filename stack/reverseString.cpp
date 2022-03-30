#include <stack>
#include <iostream>
#include <string>

void reverseString(std::string &str) {
	std::stack<char> S;
	std::string::size_type i = 0;
	while (str[i])
		S.push(str[i++]);
	for(i = 0; i < str.size(); i++) {
		str[i] = S.top();
		S.pop();
	}
}


int main() {
	std::string str("Hello");
	std::cout << str << '\n';
	reverseString(str);
	std::cout << str << '\n';
	return 0;
}

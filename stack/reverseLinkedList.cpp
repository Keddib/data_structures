#include <stack>
#include <iostream>
#include <string>
#include "../linked_list/SLinkedList.hpp"

void reverseLinkedList(Node<int> **head) {
	std::stack<Node<int> *> S;
	Node<int> *tmp = *head;
	while (tmp) {
		S.push(tmp);
		tmp = tmp->next;
	}
	tmp = *head = S.top();
	S.pop();
	while (!S.empty()) {
		tmp->next = S.top();
		S.pop();
		tmp = tmp->next;
	}
	tmp->next = 0x00;
}


int main() {
	Node<int> *head = new Node<int>(10);
	head->next = new Node<int>(20);
	head->next->next = new Node<int>(30);
	head->next->next->next = new Node<int>(40);
	Node<int> *tmp = head;
	while (tmp){
		std::cout << tmp->element << ' ';
		tmp = tmp->next;
	}
	std::cout << '\n';

	reverseLinkedList(&head);

	tmp = head;
	while (tmp){
		std::cout << tmp->element << ' ';
		tmp = tmp->next;
	}
	std::cout << '\n';
	return 0;
}

#include <iostream>
#include "BinaryTree.hpp"

// O(n) function that takes an n-node binary tree and print all nodes



void printNodes(Node<int> *T) {
	if (T == NULL)
		return ;
	printNodes(T->left);
	std::cout << T->key << '\n';
	printNodes(T->right);
}

Node<int> *maximum(Node<int> *T){
	if (T == NULL)
		return NULL;
	if (T->right == NULL)
		return T;
	return maximum(T->right);
}


int main() {
	Node<int> *T = new Node<int>(30);
	T->left = new Node<int>(20, T);
	T->right = new Node<int>(100, T);
	T->left->left = new Node<int>(10, T->left);
	printNodes(T);
}

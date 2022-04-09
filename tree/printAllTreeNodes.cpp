#include <iostream>
#include "RBT.hpp"

// O(n) function that takes an n-node binary tree and print all nodes



// void printBT(const std::string& prefix, const Node<int> * root, bool isLeft)
// {
//     if( root != nullptr )
//     {
//         std::cout << prefix;
//         std::cout << (isLeft ? "├──" : "└──" );
//         // print the value of the node
//         std::cout << root->key << std::endl;
//         // enter the next tree level - left and right branch
//         printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
//         printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
//     }
// }

// void printBT(const Node<int>* root)
// {
//     printBT("", root, false);
// }



// void printNodes(Node<int> *T) {
// 	if (T == NULL)
// 		return ;
// 	printNodes(T->left);
// 	std::cout << T->key << '\n';
// 	printNodes(T->right);
// }

// Node<int> *maximum(Node<int> *T){
// 	if (T == NULL)
// 		return NULL;
// 	if (T->right == NULL)
// 		return T;
// 	return maximum(T->right);
// }

// void leftRotation(Node<int> *T, Node<int> *x) {
// 	Node<int> *y = x->right;
// 	x->right = y->left;
// 	if (y->left != NULL)
// 		y->left->parent = x;
// 	y->parent = x->parent;
// 	if (x->parent == NULL)
// 		T = y;
// 	if (x == x->parent->left)
// 		x->parent->left = y;
// 	else x->parent->right = y;
// 	y->left = x;
// 	x->parent = y;
// }

// void rightRotation(Node<int> *T, Node<int> *x) {
// 	Node<int> *y = x->left;
// 	x->left = y->right;
// 	if (y->right != NULL)
// 		y->right->parent = x;
// 	y->parent = x->parent;
// 	if (x->parent == NULL)
// 		T = y;
// 	if (x == x->parent->left)
// 		x->parent->left = y;
// 	else x->parent->right = y;
// 	y->right = x;
// 	x->parent = y;
// }


int main() {

	ft::RBT<int> B;
	ft::node<int> *node1 = new ft::node<int>(4);
	B.insert(node1);
	node1 = new ft::node<int>(2);
	B.insert(node1);
	B.insert(node1);
	node1 = new ft::node<int>(10);
	B.insert(node1);
	node1 = new ft::node<int>(8);
	B.insert(node1);
	node1 = new ft::node<int>(13);
	B.insert(node1);
	node1 = new ft::node<int>(7);
	B.insert(node1);
	node1 = new ft::node<int>(9);
	B.insert(node1);
	node1 = new ft::node<int>(11);
	B.insert(node1);
	node1 = new ft::node<int>(15);
	B.insert(node1);
	B.printBT();
	// Node<int> *x = B.searchTree(4);
	// B.deleteNode(x);
	// B.printBT();
}

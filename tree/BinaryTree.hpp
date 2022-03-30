#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

template <typename T>
struct Node
{
	/* data */
	T	key;
	Node *parent;
	Node *left;
	Node *right;
	Node(const T &value = T(), Node *p = NULL, Node* l = NULL, Node *r = NULL)
	: key(value), parent(p), left(l), right(r)
	{}
};


template <typename U>
class Tree {

	private:
		Node<U> *_root;

	public:
		//types
		typedef U type;
		typedef U* pointer;
		typedef U& reference;
		typedef const U& const_reference;
		// methods
		Tree(): _root(NULL) {}

		void addValue(const_reference value)
		{
			// add value to tree
			if (_root != NULL) {
			}
			else
				_root = new Node<T>(value);
		}

		Node *searchTree(const_reference key)
		{
			Node *tmp = _root;
			while ( tmp != NULL && tmp->key != key)
			{
				if (key < tmp->key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return tmp;
		}

		Node *minimum()
		{
			if (_root == NULL)
				return _root;
			Node *tmp = _root;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp;
		}

		Node *maximum()
		{
			if (_root == NULL)
				return _root;
			Node *tmp = _root;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return tmp;
		}
		Node *successor(Node *x)
		{
			if (x == NULL)
				return x;
			if (x->right != NULL)
				return minimum(x->right);
			Node *y = x->p;
			while (y != NULL && x == y->right){
				x = y;
				y = y->p;
			}
			return y;
		}
		Node *predecessor(Node *x)
		{
			if (x == NULL)
				return x;
			if (x->left != NULL)
				return maximum(x->left);
			Node *y = x->p;
			while (y != NULL && x != y->right){
				x = y;
				y = y->p;
			}
			return y;
		}


};


// search tree
/*
	searchTree(T, key) {
		if ( T == NULL || T->key == key)
			return T;
		if (key < T->key)
			return searchTree(T->left, key);
		else
			return searchTree(T->right, key);
	}
	// iterative
	searchTree(T, key) {
		while ( T != NULL && T->key != key) {

			if (key < T->key)
				T = T->left;
			else
				T = T->right;
		}
		return T;
	}

*/

// inorder tree walk
/*
	INORDER-TREE-WALK(x) {

		1 if x != NIL
		2 INORDER-TREE-WALK(x:left)
		3 print x:key
		4 INORDER-TREE-WALK(x:right)
	}
*/
// preorder tree walk
// postorder tree walk
#endif

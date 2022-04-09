#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

// Binary search tree is a binary tree in which for each node,
// value of all nodes in left subtree is lesser and
// value of all the nodes on right subtree is greater.


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
class BST {

	private:
		Node<U> *_root;

	public:
		//types
		typedef U type;
		typedef U* pointer;
		typedef U& reference;
		typedef const U& const_reference;
		typedef Node<U>	node;
		// methods
		BST(): _root(NULL) {}

		void insert(const_reference value)
		{
			Node<U> *y = NULL;
			Node<U> *x = _root;
			while (x != NULL) {
				y = x;
				if (value < x->key)
					x = x->left;
				else x = x->right;
			}
			Node<U> * newNode = new Node<U>(value, y);
			if (y == NULL)
				_root = newNode; // BST was empty
			else if (value < y->key)
				y->left = newNode;
			else y->right = newNode;
		}

		void deleteNode(node *z){
			if (z->left == NULL)
				TRANSPLANT(z, z->right);
			else if (z->right == NULL)
				TRANSPLANT(z, z->left);
			else {
				node *y = minimum(z->right);
				if (y->parent != z) {
					TRANSPLANT(y , y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				TRANSPLANT(z, y);
				y->left = z->left;
				y->left->parent = y;
			}
			delete z;
		}

		node *searchTree(const_reference key) const
		{
			node *tmp = _root;
			while ( tmp != NULL && tmp->key != key)
			{
				if (key < tmp->key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return tmp;
		}

		node *minimum(node *t) const
		{
			if (t == NULL)
				return t;
			node *tmp = t;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp;
		}

		node *maximum(node *t) const
		{
			if (t == NULL)
				return t;
			node *tmp = t;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return tmp;
		}
		node *successor(node *x) const
		{
			if (x == NULL)
				return x;
			if (x->right != NULL)
				return minimum(x->right);
			node *y = x->p;
			while (y != NULL && x == y->right){
				x = y;
				y = y->p;
			}
			return y;
		}
		node *predecessor(node *x) const
		{
			if (x == NULL)
				return x;
			if (x->left != NULL)
				return maximum(x->left);
			node *y = x->p;
			while (y != NULL && x != y->right){
				x = y;
				y = y->p;
			}
			return y;
		}

		void printBT(const std::string& prefix, const Node<int> * root, bool isLeft)
		{
		    if( root != nullptr )
		    {
		        std::cout << prefix;
		        std::cout << (isLeft ? "├──" : "└──" );
		        // print the value of the node
		        std::cout << root->key << std::endl;
		        // enter the next tree level - left and right branch
		        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
		        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
		    }
		}

		void printBT()
		{
		    printBT("", _root, false);
		}

		private:
			void TRANSPLANT(node *u, node *v) {
				if (u->parent == NULL)
					_root = v;
				else if (u->parent->left == u)
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v != NULL)
					v->parent = u->parent;
			}



};


// search tree
/*
`	// recursive
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

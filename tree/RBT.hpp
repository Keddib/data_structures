#ifndef FT_RBT_HPP
#define FT_RBT_HPP

#define BLACK 0
#define RED 1

namespace ft {

// node struct
template <typename T>
struct node {
	T  key;
	bool color;
	node *p; //parent
	node *left; // left child
	node *right; // right child;
	node (const T &x = T(), node *par = NULL, node *lef = NULL, node *ri = NULL, bool col = BLACK)
	: key(x), p(par), left(lef), right(ri), color(col) {}
};


template <typename T>
class RBT {

	public: // types
		typedef	T			type;
		typedef	T&			reference;
		typedef	const T&	const_reference;
		typedef	node<T>		Node;
	private: // atributes
		Node *_NIL;
		Node *_root;

	public:
		RBT():_NIL(new Node()), _root(_NIL) {}

		void insert(Node *z) {
			Node *y = _NIL;
			Node *x = _root;
			while (x != _NIL) {
				y = x;
				if  (z->key < x->key)
					x = x->left;
				else x = x->right;
			}
			z->p = y;
			if (y == _NIL)
				_root =z;
			else if(z->key < y->key)
				y->left = z;
			else y->right = z;
			z->left = _NIL;
			z->right = _NIL;
			z->color = RED;
			insertFIXUP(z);
		}
		void deleteNode(const_reference value) {}

		Node *searchTree(const_reference key) const
		{
			Node *tmp = _root;
			while ( tmp != _NIL && tmp->key != key)
			{
				if (key < tmp->key)
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return tmp;
		}

		Node *minimum(Node *t) const
		{
			if (t == _NIL)
				return t;
			Node *tmp = t;
			while (tmp->left != _NIL)
				tmp = tmp->left;
			return tmp;
		}

		Node *maximum(Node *t) const
		{
			if (t == _NIL)
				return t;
			Node *tmp = t;
			while (tmp->right != _NIL)
				tmp = tmp->right;
			return tmp;
		}
		Node *successor(Node *x) const
		{
			if (x == _NIL)
				return x;
			if (x->right != _NIL)
				return minimum(x->right);
			Node *y = x->p;
			while (y != _NIL && x == y->right){
				x = y;
				y = y->p;
			}
			return y;
		}
		Node *predecessor(Node *x) const
		{
			if (x == _NIL)
				return x;
			if (x->left != _NIL)
				return maximum(x->left);
			Node *y = x->p;
			while (y != _NIL && x != y->right){
				x = y;
				y = y->p;
			}
			return y;
		}

		void printBT(const std::string& prefix, const Node * root, bool isLeft)
		{
		    if( root != _NIL )
		    {
		        std::cout << prefix;
		        std::cout << (isLeft ? "├──" : "└──" );
		        // print the value of the node
		        std::cout << root->key << ':' << (root->color ? 'R' : 'B') << std::endl;
		        // enter the next tree level - left and right branch
		        printBT( prefix + (isLeft ? "│   " : "    "), root->left, true);
		        printBT( prefix + (isLeft ? "│   " : "    "), root->right, false);
		    }
		}

		void printBT()
		{
		    printBT("", _root, false);
		}

	private: // mem functions

		void LEFT_ROTATE(Node *x)
		{
			Node *y = x->right;
			x->right = y->left;
			if (y->left != _NIL)
				y->left->p = x;
			y->p = x->p;
			if (x->p == _NIL)
				_root = y;
			if (x == x->p->left)
				x->p->left = y;
			else x->p->right = y;
			y->left = x;
			x->p = y;
		}

		void RIGHT_ROTATE(Node *x)
		{
			Node *y = x->left;
			x->left = y->right;
			if (y->right != _NIL)
				y->right->p = x;
			y->p = x->p;
			if (x->p == _NIL)
				_root = y;
			if (x == x->p->left)
				x->p->left = y;
			else x->p->right = y;
			y->right = x;
			x->p = y;
		}

		void insertFIXUP(Node *z) {

			while (z->p->color == RED) {

				if (z->p == z->p->p->left)
				{
					Node *y = z->p->p->right;
					if (y->color == RED) { // recolor
						z->p->color = BLACK;
						y->color = BLACK;
						z->p->p->color = RED;
						z = z->p->p;
					}
					else{ // do suitablle rotation and recolor
						if (z == z->p->right) { // LR
							z = z->p;
							LEFT_ROTATE(z);
						}
						z->p->color = BLACK; // LL
						z->p->p->color = RED;
						RIGHT_ROTATE(z->p->p);
					}
				}
				else { // z.p == z.p.p.right
					Node *y = z->p->p->left;
					if (y->color == RED) { // recolor
						z->p->color = BLACK;
						y->color = BLACK;
						z->p->p->color = RED;
						z = z->p->p;
					}
					else { // do suitablle rotation and recolor
						if (z == z->p->left) { // RL
							z = z->p;
							RIGHT_ROTATE( z);
						}
						z->p->color = BLACK; // RR
						z->p->p->color = RED;
						LEFT_ROTATE( z->p->p);
					}
				}
			}
			_root->color = BLACK;
		}
};

} // ft

#endif

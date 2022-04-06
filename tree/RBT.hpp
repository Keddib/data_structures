#ifndef FT_RBT_HPP
#define FT_RBT_HPP


namespace ft {

// node struct
template <typename T>
struct node {
	T  key;
	bool c_;
	node *p_; //parent
	node *l_; // left child
	node *r_; // right child;
	node (const T &x = T(), node *p = NULL, node *l = NULL, node *r = NULL, bool c = 0)
	: key(x), p_(p), l_(l), r_(r), c_(c) {}
};


template <typename T>
class RBT {

	public: // types
		typedef	T			type;
		typedef	T&			reference;
		typedef	const T&	const_reference;
	private: // atributes
		node<T> *_NIL;
		node<T> *_root;


};

} // ft

#endif

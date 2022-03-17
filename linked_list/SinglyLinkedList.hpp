#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP


template <typename T>
class Node {
	public:
		T element;
		Node *next;

	public:
		Node(const T &x, Node *p = 0) : element(x), next(p) {}
		~Node() {}
}


template <typename T>
class SinglyLinkedList
{
	private:
		/* data */
		Node *_head;
	public:
		// types
		typedef T			type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef const T&	const_reference;


		SinglyLinkedList() : _head(NULL) {
		}

		SinglyLinkedList(const_reference x) {
			_head = new Node(x);
		}
		~SinglyLinkedList();

		void addNode(const_reference x) {

			Node *p = new Node(x);
			if (_head) {
				Node *tmp = _head;
				while (tmp)
					tmp = tmp->next;
				tmp->next = p;
			}
			_head = p;
		}
};





#endif

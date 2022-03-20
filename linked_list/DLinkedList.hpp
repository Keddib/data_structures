#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <typeinfo>


template <typename T>
class Node {
	public:
		T element;
		Node *next, *prev;

	public:
		Node(const T &x, Node *p = 0, Node *p = 0)
		: element(x), next(p), prev(p) {}
		~Node() {}
};


template <typename T>
class List
{
	private:
		/* data */
		Node<T> *_head, *_tail;
		size_t _size;
	public:
		// types
		typedef T			type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef const T&	const_reference;


		List() : _head(NULL), _size(0) {
			_head = _tail = 0;
			_size = 0;
		}

		List(const_reference x) {
			_head = new Node<T>(x);
			_tail = _head;
			_size = 1;
		}
		~List() {
			while (_head) {
				Node<T> *tmp = _head->next;
				delete _head;
				_head = tmp;
			}
		}


		bool isEmpty() { return _head == 0; }

		size_t length() const { return _size; }

		void addToHead(const_reference x) {
			_head = new Node<T>(x, _head);
			if (_head->next)
				_head->next->prev = _head;
			if (_tail == 0)
				_tail = _head;
			_size++;
		}

		void addToTail(const_reference x) {
			if (_tail) { // list not empty
				_tail = new Node<T>(x, 0, _tail);
				_tail->prev->next = _tail;
			} else _head = _tail = new Node<T>(x);
			_size++;
		}

		void deleleNode(const_reference x) {
			Node<T> *tmp, *prev;
			if (_head == _tail && _head && _head->element == x) { // if one node
				delete _head;
				_head = _tail = NULL;
				_size--;
			}
			else if (_head && _head->element == x) {
				tmp = _head;
				_head = _head->next;
				delete tmp;
				_size--;
			}
			for ( prev = _head, tmp = _head->next; tmp != NULL; prev = prev->next, tmp = tmp->next) {
				if (tmp->element == x){
					Node<T> *t = tmp;
					tmp = tmp->next;
					prev->next = tmp->next;
					if (_tail == tmp)
						_tail = prev;
					delete tmp;
					_size--;
				}
			}
		}

		type deleleFromHead() {
			type x = _head->element;
			Node<T> *tmp = _head;
			if (_head == _tail)
				_head = _tail = 0x00;
			else{
				_head = _head->next;
				_head->next->prev = 0x00;
			}
			delete tmp;
			_size--;
			return x;
		}

		type deleleFromTail() {
			type x = _tail->element;
			if (_tail == _head) {
				delete _tail;
				_tail = _head = NULL;
			} else {
				_tail = _tail->prev;
				delete _tail->next;
				_tail->next = NULL;
			}
			_size--;
			return x;
		}

		bool isInList(const_reference x) {
			Node<T> *tmp;
			for (tmp = _head; tmp != NULL; tmp = tmp->next)
				if (tmp->element == x)
					return 1;
			return 0;
		}


};

#endif

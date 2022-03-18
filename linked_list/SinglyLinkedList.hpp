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
};


template <typename T>
class List
{
	private:
		/* data */
		Node *_head, *_tail;
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
			_head = new Node(x);
			_tail = _head;
			_size = 1;
		}
		~List() {}


		bool isEmpty() { return _head == 0; }

		size_t length() const { return _size; }

		void addToHead(const_reference x) {
			_head = new Node(x, _head);
			if (_tail == 0)
				_tail = _head;
			_size++;
		}

		void addToTail(const_reference x) {
			if (_tail) { // list not empty
				_tail->next = new Node(x);
				_tail = _tail->next;
			} else _head = _tail = new Node(x);
			_size++;
		}

		void deleleNode(const_reference x) {
			Node *tmp, *prev;
			if (_head == _tail && _head && _head->element == x) { // if one node
				delete _head
				_head = _tail = NULL;
			}
			else if (_head && _head->element == x) {
				tmp = _head;
				_head = _head->next;
				delete tmp;
			}
			for ( = _head; tmp != NULL; tmp = tmp->next) {
				if (tmp->element == x){
					Node *t = tmp;
					tmp = tmp->next;
				}
			}
		}

		int deleleFromHead() {
			if (_head) {
				type x = _head->element;
				Node *tmp = _head;
				if (_head == _tail)
					_head = _tail = 0;
				else
					_head = _head->next;
				delete tmp;
				_size--;
				return x;
			}
			return 0;
		}

		void deleleFromTail() {
			if (_tail) {
				type x = _tail->element;
				if (_tail == _head) {
					delete _tail;
					_tail = _head = NULL;
				} else {
					Node *tmp;
					for (tmp = _head; tmp->next != _tail; tmp = tmp->next); // fine last element befor tail
					delete _tail;
					_tail = tmp;
					_tail->next = NULL;
				}
				_size--;
				return x;
			}
		}

		bool isInList(const_reference x) {
			Node *tmp;
			for (tmp = _head; tmp != NULL; tmp = tmp->next)
				if (tmp->element == x)
					return 1;
			return 0;
		}


};





#endif

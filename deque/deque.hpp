#ifndef DEQUE_007_HPP
#define DEQUE_007_HPP

/*
** A Deque is a generalization of both the FIFO Queue and LIFO Queue
** (Stack). A Deque represents a sequence of elements, with a front and a
** back. Elements can be added at the front of the sequence or the back of
** the sequence. The names of the Deque operations are self-explanatory:
** addFirst(x), removeFirst(), addLast(x), and removeLast(). It is worth
** noting that a Stack can be implemented using only addFirst(x) and
** removeFirst() while a FIFO Queue can be implemented using addLast(x)
** and removeFirst().
*/

// generic Deque implementation with a doubly linked list

#include <list>


template<typename T>
class Deque
{
	private:
		/* data */
		list<T> lst;

	public:
		Deque(/* args */) {}

		~Deque() { lst.clear(); }

		void clear() { lst.clear(); }

		bool isEmpty() const { lst.empty(); }

		T& front() { lst.front(); }

		T& back() { lst.back(); }

		void addFirst(const T &x) {
			lst.push_front(x);
		}

		T removeFirst() {
			T tmp = front();
			lst.pop_front();
			return tmp;
		}

		void addLast(const T &x) {
			lst.push_back();
		}

		T removeLast() {
			T tmp = back();
			lst.pop_back();
			return tmp;
		}
};


#endif

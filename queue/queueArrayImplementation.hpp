#ifndef QUEUE_007_HPP
#define QUEUE_007_HPP

/*
** A queue is simply a waiting line that grows by adding elements to its end and shrinks by taking elements from its front.
** Unlike a stack, a queue is a structure in which both ends are used: one for adding new elements and one for removing
** them. Therefore, the last element has to wait until all elements preceding it on the queue are removed. A queue is an FIFO
** structure: First in/First out.
*/

// generic queue implementation with a circular array

#include <list>


template<typename T>
class queue
{
	private:
		/* data */
		list<T> lst;

	public:
		queue(/* args */) {}
		~queue() { lst.clear(); }
		void clear() { lst.clear(); }
		bool isEmpty() const { lst.empty(); }
		T& front() { lst.front(); }
		T dequeue() {
			T x = lst.front();
			lst.pop_front();
			return x;
		}
		void enqueue(const T &el) {
			lst.push_back(el);
		}
};


#endif

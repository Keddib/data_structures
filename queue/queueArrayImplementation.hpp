#ifndef QUEUE_007_HPP
#define QUEUE_007_HPP

/*
** A queue is simply a waiting line that grows by adding elements to its end and shrinks by taking elements from its front.
** Unlike a stack, a queue is a structure in which both ends are used: one for adding new elements and one for removing
** them. Therefore, the last element has to wait until all elements preceding it on the queue are removed. A queue is an FIFO
** structure: First in/First out.
*/

// generic queue implementation with a circular array

#define BUFF_SIZE 24

template<typename T>
class queue
{
	private:
		/* data */
		T array[BUFF_SIZE];
		int front;
		int rear;

	public:
		queue(/* args */): front(-1), rear(-1) {}
		~queue() { }
		void clear() { front = rear = -1; }
		bool isEmpty() const { return (front == -1 && rear == -1); }
		const T& frontt() { return array[front]; }

		void dequeue() {
			if (isEmpty())
				return;
			else if (front == rear)
				front = rear = -1;
			else
				front = (front + 1) % BUFF_SIZE;
		}
		void enqueue(const T &el) {
			if ((rear + 1) % BUFF_SIZE == front) // is full
				return ;
			else if (isEmpty()) // is empty
				rear = front = 0;
			else
				rear = (rear + 1) % BUFF_SIZE;
			array[rear] = el;
		}

		void print() {}
};


#endif

#define SIZE 10
namespace vmk {
template <class T> class Stack {
public:
	Stack();
	void push(T elem);
	T pop();
	bool isFull();
	bool isEmpty();
	T top_element();
private:
	int _top;
	T _elems[SIZE];
};

template <class T> Stack<T>::Stack() {_top = -1;}

template <class T> void Stack<T>::push(T elem) {
	if (isFull()) {
		throw std::runtime_error("attempt to push to full stack!");
	}

	_top = _top + 1;
	_elems[_top] = elem;
}

template <class T> bool Stack<T>::isEmpty() {
	return (_top == -1);
}

template <class T> bool Stack<T>::isFull() {
	return (_top == (SIZE-1));
}

template <class T> T Stack<T>::pop() {
	T popped = _elems[_top];
	_top--;
	return popped;
}

template <class T> T Stack<T>::top_element() {
	T top_element = _elems[_top];
	return top_element;
}
}

#include "AbstractStack.h";

template <typename T>
class myStack : public AbstractStack<T>
{
private:
	T* stack;       
	int capacity;
		int topIndex;
public:
	myStack(int size) : capacity(size), topIndex(0) 
	{
		stack = new T[capacity]; // Allocate array
	}

	~myStack() 
	{
		delete[] stack; // Free allocated memory
	}

	void push(T value) override 
	{
		if (isFull())
		{
			cout << "Stack is full, cannot push " << value << endl;
			return;
		}
		stack[topIndex++] = value; // Add value and increment top index
	}

	T pop() override 
	{
		if (isEmpty()) 
		{
			cout << "Stack is empty, cannot pop" << endl;
			return T(); // Return default value
		}
		return stack[--topIndex]; // Decrement top index and return value
	}

	T top() const override {
		if (isEmpty()) {
			cout << "Stack is empty, cannot retrieve top" << endl;
			return T(); // Return default value
		}
		return stack[topIndex - 1]; // Return top value
	}

	bool isEmpty() const override {
		return topIndex == 0; // Check if top index is zero
	}

	bool isFull() const override {
		return topIndex >= capacity; // Check if top index exceeds capacity
	}

	void display() const {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
			return;
		}
		cout << "Stack contents: ";
		for (int i = 0; i < topIndex; ++i) {
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};
#include "AbstractStack.h"

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
		stack = new T[capacity];
	}

	~myStack()
	{
		delete[] stack;
	}

	void push(T value) override
	{
		if (isFull())
		{
			cout << "Stack is full, cannot push " << value << endl;
			return;
		}
		stack[topIndex++] = value;
	}

	int getCapacity() const
	{
		return capacity;
	}

	T pop() override
	{
		if (isEmpty())
		{
			cout << "Stack is empty, cannot pop" << endl;
			return T();
		}
		return stack[--topIndex];
	}

	T top() const override
	{
		if (isEmpty())
		{
			cout << "Stack is empty, cannot retrieve top" << endl;
			return T();
		}
		return stack[topIndex - 1];
	}

	bool isEmpty() const override
	{
		return topIndex == 0;
	}

	bool isFull() const override
	{
		return topIndex >= capacity;
	}

	void display() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return;
		}
		cout << "Stack contents: ";
		for (int i = 0; i < topIndex; ++i)
		{
			cout << stack[i] << " ";
		}
		cout << endl;
	}
};
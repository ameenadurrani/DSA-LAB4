#include "myStack.h"
#include <string>

template <typename T>
myStack<T> reverseStack(myStack<T>& original) 
{
	myStack<T> reversed(original.getCapacity()); 

	if (original.isEmpty())
	{
		cout << "Original stack is empty, nothing to reverse." << endl;
		return reversed;
	}

	while (!original.isEmpty()) 
	{
		T value = original.pop(); 
		reversed.push(value); 
	}

	return reversed;
}


template <typename T>
void reverseStackInPlace(myStack<T>& original, myStack<T>& reversed)
{
	reversed = reverseStack(original);
}

int main() 
{
	const int stackSize = 5; 
	myStack<string> stack(stackSize);
	myStack<string> reversedStack(stackSize);
	int choice;
	string value;

	do 
	{
		cout << "\nLibrary Stack Menu:\n";
		cout << "1. Push book title\n";
		cout << "2. Reverse stack\n";
		cout << "3. Display stack\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) 
		{
			cout << "Enter book title to push: ";
			cin >> value;
			stack.push(value);
		}
		else if (choice == 2) 
		{
			reverseStackInPlace(stack, reversedStack); // Reverse the original stack
			cout << "Stack reversed!" << endl;
		}
		else if (choice == 3) 
		{
			stack.display();
		}
		else if (choice == 0) 
		{
			cout << "Exiting..." << endl;
		}
		else 
		{
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}

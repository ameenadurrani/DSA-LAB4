#include "myStack.h";

int main() 
{
	const int stackSize = 5; 
	myStack<int> stack(stackSize);
	int choice, value;

	do {
		cout << "\nStack Menu:\n";
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Top\n";
		cout << "4. Check if Empty\n";
		cout << "5. Check if Full\n";
		cout << "6. Display Stack\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter value to push: ";
			cin >> value;
			stack.push(value);
		}
		else if (choice == 2) 
		{
			
				value = stack.pop(); 
				cout << "Value popped: " << value << endl; 


		}
		else if (choice == 3)
		{
			value = stack.top();
			if (!stack.isEmpty()) 
			{
				cout << "Top value: " << value << endl;
			}
		}
		else if (choice == 4) 
		{
			if (stack.isEmpty()) 
			{
				cout << "Stack is empty" << endl;
			}
			else 
			{
				cout << "Stack is not empty" << endl;
			}
		}
		else if (choice == 5) 
		{
			if (stack.isFull()) 
			{
				cout << "Stack is full" << endl;
			}
			else
			{
				cout << "Stack is not full" << endl;
			}

		}
		else if (choice == 6) 
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
	} 
	while (choice != 0);

	return 0;
}

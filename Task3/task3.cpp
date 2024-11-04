#include <iostream>
#include <string>
#include "myStack.h"

using namespace std;

bool areBracketsBalanced(const string& expression) 
{
	myStack<char> stack(expression.length());
	for (char ch : expression) 
	{
		if (ch == '(' || ch == '[' || ch == '{') 
		{
			stack.push(ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') 
		{
			if (stack.isEmpty())
			{
				return false; 
			}
			char top = stack.pop();
			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{'))
			{
			}
		}
	}

	return stack.isEmpty();
}

int main() 
{
	string expression;
	int choice;

	do {
		cout << "\nBracket Balancing Checker Menu:\n";
		cout << "1. Check expression\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter an expression to check for balanced brackets: ";
			cin >> expression;
			if (areBracketsBalanced(expression))
			{
				cout << "The brackets are balanced." << endl;
			}
			else 
			{
				cout << "The brackets are not balanced." << endl;
			}
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

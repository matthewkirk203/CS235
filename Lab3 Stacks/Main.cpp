#include "ExpressionManager.h"

using namespace std;


string menu()
{
	string choice = "0";
	cout << "Choose something\n" << "1.IsBalanced\n2.Postfix->Infix\n3.Infix->Postfix\n4.PostfixEvaluate\n";
	getline(cin, choice);
	return choice;
}

int main()
{
	ExpressionManager thingy;
	while (true)
	{
		string expression = "";
		string choice = menu();
		if (choice == "1")
		{
			cout << "Enter expression" << endl;
			getline(cin, expression); //getline not working
			bool balanced = thingy.isBalanced(expression);
			if (balanced)
			{
				cout << "Balanced!\n";
			}
			else
			{
				cout << "Not Balanced :(\n";
			}
		}
		else if (choice == "2")
		{
			cout << "Running Postfix->Infix\n";
			cout << "Enter postfix expression\n";
			getline (cin, expression);
			string result = thingy.postfixToInfix(expression);
			cout << result << endl;
		}
		else if (choice == "3")
		{
			cout << "Enter infix expression\n";
			//getline(cin, expression);
			expression = "40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6";
			string result = thingy.infixToPostfix(expression);
			cout << "Result: " << result << endl;
		}
		else if (choice =="4")
		{
			cout << "Enter postfix expression\n";
			getline (cin, expression);
			string result = thingy.postfixEvaluate(expression);
			cout << result << endl;
		}

	}
	return 0;
}
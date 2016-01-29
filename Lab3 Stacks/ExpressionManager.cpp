#include "ExpressionManager.h"
#include <stack> 
#include <sstream>
#include <stdlib.h>
/*
Questions:
How to deal with 4.3?
Dealing with invaid forms like 1 + 2 +

Answers:
isValid function
a to i | a to f -- or -- for loop through the string to check if it is valid.
*/
ExpressionManager::ExpressionManager(void)
{
}


ExpressionManager::~ExpressionManager(void)
{
}
bool ExpressionManager::isValid(string expression)
{
	if (!isBalanced(expression))
	{return false;}
	istringstream s;
	s.str(expression);
	int opcount = 0;
	int intcount = 0;
	while (!s.eof())
	{
		string current = "";
		s >> current;
		if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
		{opcount++;}
		else if (isdigit(current[0]))
		{intcount++;}
	}
	if (intcount == (opcount + 1))
	{return true;}
	else
	{return false;}
}
/*
Precidence Levels: * / %   <--highest
+ -
( { [   <--lowest, kind of
*/
bool ExpressionManager::higherPrecidence(string current, string topOfStack)
{
	if (current == "*" || current == "/" || current == "%")
	{
		if (topOfStack == "*" || topOfStack == "/" || topOfStack == "%")
		{return false;}

		else
		{return true;}
	}
	else if (current == "+" || current == "-")
	{
		if (topOfStack == "+" || topOfStack == "-" || topOfStack == "*" || topOfStack == "/" || topOfStack == "%")
		{return false;}

		else
		{return true;}
	}
	else if (current == "(" || current == "[" || current == "{") //This one is a little wibbly wobbly. We'll try it.
	{return false;}

	else //this shouldn't happen
	{
		cout << "slow down tiger, something went wrong\n";
		system("pause");
	}
}
//Done!
bool ExpressionManager::isBalanced(string expression)
{
	istringstream s;
	s.str(expression);
	stack<string> stack;
	//While string stream is not at the end of expression,
	//check what each character is.
	while (!s.eof())
	{
		string current;
		s >> current;

		//Open Parend checks
		if (current == "(")
		{
			stack.push(current);
		}
		else if (current == "[")
		{
			stack.push(current);
		}
		else if (current == "{")
		{
			stack.push(current);
		}

		//Closed Parend checks.
		else if (current == ")")
		{
			if (stack.empty()) {return false;}
			if (stack.top() == "(")
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
		else if (current == "]")
		{
			if (stack.empty()) {return false;}
			if (stack.top() == "[")
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
		else if (current == "}")
		{
			if (stack.empty()) {return false;}
			if (stack.top() == "{")
			{
				stack.pop();
			}
			else
			{
				return false;
			}
		}
	}
	if (stack.empty())
	{return true;}
	else
	{return false;}
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	if (!isBalanced(postfixExpression)) {return "invalid";}
	istringstream s;
	s.str(postfixExpression);
	stack<string> stack;
	string result = "";
	while (!s.eof())
	{
		string current;
		s >> current;
		if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
		{ 
			string sp = " ";
			string op = current;
			//size check
			if (stack.empty())
			{return "invalid";}

			string b = stack.top();
			stack.pop();
			//size check
			if (stack.empty())
			{return "invalid";}

			string a = stack.top();
			stack.pop();

			result = "(" + sp + a + sp + op + sp + b + sp + ")";
			stack.push(result);
		}
		else if (isdigit(current[0]))
		{
			for (unsigned int i = 0; i < current.size(); i++)
			{
				if (!isdigit(current[i]))
				{return "invalid";}
			}
			stack.push(current);
		}
		else
		{return "invalid";}
	}
	if (stack.size() == 1)
	{return stack.top();}
	else
	{return "invalid";}
	return "NULL";
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	if (!isValid(infixExpression)) {return "invalid";}
	istringstream s;
	s.str(infixExpression);
	stack<string> stack;
	string sp = " ";
	string result = "";
	while(!s.eof())
	{
		string current;
		s >> current;

		if (isdigit(current[0]))
		{
			for (unsigned int i = 0; i < current.size(); i++)
			{
				if (!isdigit(current[i]))
				{return "invalid";}
			}
			result += current + sp;
		}

		else if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
		{
			if (stack.empty())
			{
				stack.push(current);
			}
			else if (higherPrecidence(current, stack.top()))
			{
				stack.push(current);
			}
			else if (!higherPrecidence(current, stack.top()))
			{
				result += stack.top() + sp;
				stack.pop();
				stack.push(current);

				/*while (!higherPrecidence(current, stack.top())) //Minus sign isn't being pushed on. Can't figure it out. Use breakpoints. See ya.
				{
				//pop until lower precidence
				result += stack.top() + sp;
				stack.pop();
				if (stack.empty())
				{
				stack.push(current);
				break;
				}
				}*/
			}
		}

		else if (current == "(" || current == "[" || current == "{")
		{
			stack.push(current);
		}
		else if (current == ")" || current == "]" || current == "}")//pop until parend
		{
			while (stack.top() != "(" && stack.top() != "[" && stack.top() != "{") 
			{
				result += stack.top() + sp;
				stack.pop();
			}
			if (stack.top() == "(" || stack.top() == "[" || stack.top() == "{")
			{
				stack.pop();
			}
		}
		else
		{return "invalid";}
	}
	//at eof pop off the rest of the stack
	while (stack.size() > 1)
	{
		//pop until lower precidence
		result += stack.top() + sp;
		stack.pop();
	}
	result += stack.top();
	return result;
}
//Done!
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	istringstream s;
	s.str(postfixExpression);
	stack<int> stack;
	int result = 0;
	//Balance Check
	if (!isBalanced(postfixExpression)) {return "invalid";}

	while (!s.eof()) //pull out two ints, apply operator, push in result
	{
		string current;
		s >> current;
		if (current == "+" || current == "-" || current == "/" || current == "*" || current == "%")
		{ 
			int a, b = 0;
			if (!stack.empty())//size check
			{b = stack.top();
			stack.pop();}

			else
			{return "invalid";}

			if (!stack.empty())//size check
			{a = stack.top();
			stack.pop();}

			else
			{return "invalid";}

			//Determining sign
			if (current == "+")
			{result = a + b;}

			else if (current == "-")
			{result = a - b;}

			else if (current == "/")
			{
				if (b == 0)
				{
					cout << "Divide by zero\n";
					return "invalid";
				}
				else
				{
					result = a / b;
				}
			}

			else if (current == "*")
			{result = a * b;}

			else if (current == "%")
			{
				if (b == 0)
				{
					cout << "Mod by zero\n";
					return "invalid";
				}
				else
				{
					result = a % b;
				}
			}

			stack.push(result);
		}
		else if (isdigit(current[0])) //cast string to int?
		{
			istringstream stringToInt;
			stringToInt.str(current);
			int currentAsInt;
			stringToInt >> currentAsInt;
			stack.push(currentAsInt);
			result = currentAsInt;
		}
		else
		{return "invalid\n";}
	}

	if (stack.size() != 1)
	{
		return "invalid";
	}
	stringstream intToString;
	intToString << result;

	return intToString.str();
}
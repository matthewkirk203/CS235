#pragma once
#include "ExpressionManagerInterface.h"
class ExpressionManager :
	public ExpressionManagerInterface
{
public:
	ExpressionManager(void);
	~ExpressionManager(void);
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);
	bool higherPrecidence(string current, string topOfStack);
	bool isValid(string expression);
};


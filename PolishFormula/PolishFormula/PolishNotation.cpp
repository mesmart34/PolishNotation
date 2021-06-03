#include "PolishNotation.h"

using namespace std; 

int PolishNotation::OpPreced(const char c) const
{
	switch (c)
	{
	case '!':
		return 4;

	case '*':
	case '/':
	case '%':
		return 3;

	case '+':
	case '-':
		return 2;

	case '=':
		return 1;
	}
	return 0;
}

bool PolishNotation::OpLeftAssoc(const char c) const
{
	switch (c)
	{
	case '*':
	case '/':
	case '%':
	case '+':
	case '-':
	case '=':
		return true;
	case '!':
		return false;
	}
	return false;
}

uint32_t PolishNotation::OpArgCount(const char c) const
{
	switch (c)
	{
	case '*':
	case '/':
	case '%':
	case '+':
	case '-':
	case '=':
		return 2;
	case '!':
		return 1;

	default:
		return c - 'A';
	}
	return 0;
}


bool PolishNotation::IsStringNumber(const char token) const
{
	return ('0' <= token && token <= '9') || ('a' <= token && token <= 'z');
}

std::string PolishNotation::Convert(const std::string& infix)
{
	std::stack<char> stack;
	auto output = std::queue<char>();
	char sc = 0;
	for (auto token : infix)
	{
		if(token == ' ')
			continue;
		if (IsStringNumber(token))
		{
			output.push(token);
		}
		else if (IsFunction(token))
		{
			stack.push(token);
		}
		else if (token == ',')
		{
			auto pe = false;
			while (stack.size() > 0)
			{
				sc = stack.top();
				if (sc == '(')
				{
					pe = true;
					break;
				}
				else {
					output.push(sc);
					stack.pop();
				}
			}
			if (!pe)
			{
				throw "Separator or parentheses are mismatched";
			}
		}
		else if (IsOperator(token))
		{
			while (stack.size() > 0)
			{
				sc = stack.top();
				if (IsOperator(sc) &&
					((OpLeftAssoc(token) && (OpPreced(token) <= OpPreced(sc)))
						||
						(!OpLeftAssoc(token) && (OpPreced(token) < OpPreced(sc))))) 
				{
					output.push(sc);
					stack.pop();
				}
				else {
					break;
				}
			}

			stack.push(token);
		}
		else if (token == '(')
		{
			stack.push(token);
		}
		else if (token == ')')
		{
			auto pe = false;
			while (stack.size() > 0)
			{
				sc = stack.top();
				if (sc == '(')
				{
					pe = true;
					break;
				}
				else
				{
					output.push(sc);
					stack.pop();
				}
			}

			if (!pe)
			{
				throw "Separator or parentheses are mismatched";
			}
			stack.pop();
			if (stack.size() > 0)
			{
				sc = stack.top();
				if (IsFunction(sc))
				{
					output.push(sc);
					stack.pop();
				}
			}
		}
		else {
			throw "Unknown token " + sc;
		}
	}
	while (stack.size() > 0)
	{
		sc = stack.top();
		if (sc == '(' || sc == ')')
		{
			throw "Parentheses are mismatched";
		}
		output.push(sc);
		stack.pop();
	}
	auto result = std::string();
	while (output.size() > 0) {
		result += output.front();
		result += ' ';
		output.pop();
	}
	return result;
}

bool PolishNotation::IsFunction(const char token) const
{
	return (token >= 'A' && token <= 'Z');
}

bool PolishNotation::IsOperator(const char token) const
{
	return (token == '+' || token == '-' || token == '/' || token == '*' || token == '!' || token == '%' || token == '=');
}

std::vector<std::string> PolishNotation::SplitIntoTokens(const std::string& text) const
{
	std::istringstream iss(text);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());
	return results;
}


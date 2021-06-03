#pragma once

#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <istream>
#include <sstream>
#include <iostream>

class PolishNotation
{
public:
	PolishNotation() = default;
	
	std::string Convert(const std::string& infix);

private:

	bool IsStringNumber(const char token) const;
	bool IsFunction(const char token) const;
	bool IsOperator(const char token) const;
	int OpPreced(const char c) const;
	bool OpLeftAssoc(const char c) const;
	uint32_t OpArgCount(const char c) const;

	std::vector<std::string> SplitIntoTokens(const std::string& line) const;

};


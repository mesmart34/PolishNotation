#include "PolishNotation.h"
#include <iostream>

int main()
{
	auto pn = PolishNotation();

	std::string line;

	while(true)
	{
		std::getline(std::cin, line);
		if (line == "stop")
			break;
		std::cout << pn.Convert(line) << std::endl;
	} 

	return 0;
}
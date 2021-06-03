#include "PolishNotation.h"
#include <iostream>

int main()
{
	auto pn = PolishNotation();
	std::cout << pn.Convert("f = D(2 + (4 / 3) + 6 * (3 - 2))") << std::endl;
	return 0;
}
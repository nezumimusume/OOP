#include <iostream>
#include "Gobrin.h"

Gobrin::Gobrin()
{
	std::cout << "�S�u�������X�|�[������܂����B\n";
}

Monster* Gobrin::Clone()
{
	return new Gobrin;
}
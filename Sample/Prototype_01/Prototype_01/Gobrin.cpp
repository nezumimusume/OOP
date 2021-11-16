#include <iostream>
#include "Gobrin.h"

Gobrin::Gobrin()
{
	std::cout << "ゴブリンがスポーンされました。\n";
}

Monster* Gobrin::Clone()
{
	return new Gobrin;
}
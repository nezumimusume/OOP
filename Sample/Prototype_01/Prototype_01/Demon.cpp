#include <iostream>
#include "Demon.h"

Demon::Demon()
{
	std::cout << "デーモンがスポーンされました。\n";
}
Monster* Demon::Clone()
{
	return new Demon;
}
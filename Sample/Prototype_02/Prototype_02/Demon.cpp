#include <iostream>
#include "Demon.h"

Demon::Demon()
{
	std::cout << "�f�[�������X�|�[������܂����B\n";
}
Monster* Demon::Clone()
{
	return new Demon;
}
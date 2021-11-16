#include <iostream>
#include "Slime.h"

Slime::Slime()
{
	std::cout << "スライムがスポーンされました。\n";
}

// クローンを作成。
Monster* Slime::Clone()
{
	return new Slime;
}
#pragma once
#include "Monster.h"

class Gobrin : public Monster
{
public:
	// コンストラクタ。
	Gobrin();
	// クローン。
	Monster* Clone() override;
};


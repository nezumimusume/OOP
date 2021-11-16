#pragma once
#include "Monster.h"

// スライム。
class Slime : public Monster
{
public:
	// コンストラクタ。
	Slime();
	// クローンを作成。
	Monster* Clone() override;
};


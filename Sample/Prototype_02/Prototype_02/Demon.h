#pragma once
#include "Monster.h"

// デーモン
class Demon : public Monster
{
public:
	// コンストラクタ。
	Demon();
	// クローンを生成。
	Monster* Clone() override;
};


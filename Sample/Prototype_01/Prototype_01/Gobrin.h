#pragma once
#include "Monster.h"

class Gobrin : public Monster
{
public:
	// �R���X�g���N�^�B
	Gobrin();
	// �N���[���B
	Monster* Clone() override;
};


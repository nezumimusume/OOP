#pragma once
#include "Monster.h"

// �f�[����
class Demon : public Monster
{
public:
	// �R���X�g���N�^�B
	Demon();
	// �N���[���𐶐��B
	Monster* Clone() override;
};


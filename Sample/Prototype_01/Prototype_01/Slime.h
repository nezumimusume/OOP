#pragma once
#include "Monster.h"

// �X���C���B
class Slime : public Monster
{
public:
	// �R���X�g���N�^�B
	Slime();
	// �N���[�����쐬�B
	Monster* Clone() override;
};


#include <iostream>
#include "Slime.h"

Slime::Slime()
{
	std::cout << "�X���C�����X�|�[������܂����B\n";
}

// �N���[�����쐬�B
Monster* Slime::Clone()
{
	return new Slime;
}
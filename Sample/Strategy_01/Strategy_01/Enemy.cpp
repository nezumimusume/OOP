#include "Enemy.h"


void Enemy::Update()
{
	if (m_move) {
		// �ړ����������s�B
		m_move->Execute();
	}
}
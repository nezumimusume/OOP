#include "Enemy.h"


void Enemy::Update()
{
	if (m_move) {
		// ˆÚ“®ˆ—‚ðŽÀsB
		m_move->Execute();
	}
}
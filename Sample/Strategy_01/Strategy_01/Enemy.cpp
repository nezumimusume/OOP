#include "Enemy.h"


void Enemy::Update()
{
	if (m_move) {
		// 移動処理を実行。
		m_move->Execute();
	}
}
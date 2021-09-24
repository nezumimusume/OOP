#include "stdafx.h"
#include <random>
#include "EnemyRandomMove.h"

// step-2 敵キャラクターのランダム移動クラスの定義を実装する。
void EnemyRandomMove::Execute(Vector3& pos)
{
    // ランダムに移動速度を決定。
	if (m_moveTimer % 120 == 0) {
		// 120フレームで移動方向を変更する。
		std::random_device rd;
		m_moveSpeed.x = (rd() % 100) / 100.0f;
		m_moveSpeed.x -= 0.5f;
		m_moveSpeed.z = (rd() % 100) / 100.0f;
		m_moveSpeed.z -= 0.5f;
		// 正規化する。
		m_moveSpeed.Normalize();
		// 移動速度は0.3。
		m_moveSpeed *= 0.3f;
	}
	// 移動タイマーをインクリメント
	m_moveTimer++;
	// 移動速度を座標に加算。
	pos += m_moveSpeed;
}

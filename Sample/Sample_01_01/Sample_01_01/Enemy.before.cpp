#include "stdafx.h"
#include "Enemy.before.h"
#include <random>

Enemy::Enemy()
{
	// モデル描画処理を初期化。
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/enemy/enemy.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
}
/// <summary>
/// 毎フレーム呼ばれる更新処理。
/// </summary>
void Enemy::Update()
{
	// point-2 ランダム移動に関する処理
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
	m_position += m_moveSpeed;
	// point-2 ここまで

	// ワールド行列を更新。
	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}
/// <summary>
/// 毎フレーム呼ばれる描画処理。
/// </summary>
/// <param name="rc"></param>
void Enemy::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
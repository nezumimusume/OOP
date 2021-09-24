#include "stdafx.h"
#include "Enemy.h"
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
	// step-4 移動処理をEnemyRandomMoveに委譲する。

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
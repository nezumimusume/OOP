#include "stdafx.h"
#include "Player.h"
#include "InGame.h"
#include "Enemy.h"

Player::Player()
{
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
	m_position.x = 1000.0f;
	m_position.z = 950.0f;
}

void Player::Update(InGame& inGame)
{
	auto oldState = m_state;
	switch (m_state) {
	case enState_Idle:
		if (g_pad[0]->IsTrigger(enButtonA)) {
			// ジャンプする。
			// 上に移動する速度を設定する。
			m_moveSpeed.y = 20.0f;
			m_state = enState_Jump;
		}
		
		if (g_pad[0]->GetLStickXF() != 0.0f
			|| g_pad[0]->GetLStickYF() != 0.0f)
		{
			// 左スティックの移動量があったら移動状態に遷移する。
			m_state = enState_Move;
		}
		break;
	case enState_Jump:
		// ジャンプ中。
		// 重力加速度を移動速度のY方向に加える。
		m_moveSpeed.y -= 1.5f;
		// 座標に移動速度を加算する。
		m_position += m_moveSpeed;
		if ( m_position.y < 0.0f ) {
			m_position.y = 0.0f;
			// 地面についたので、待機状態に遷移する。
			m_state = enState_Idle;
		}
		break;
	case enState_Move: 
		if (g_pad[0]->GetLStickXF() == 0.0f
			|| g_pad[0]->GetLStickYF() == 0.0f)
		{
			// 左スティックの入力がない
			m_state = enState_Idle;
		}
		// 移動ステート。
		m_moveSpeed.x = g_pad[0]->GetLStickXF() * -5.0f;
		m_moveSpeed.z = g_pad[0]->GetLStickYF() * -5.0f;
		if (m_moveSpeed.x != 0.0f || m_moveSpeed.z != 0.0f) {
			m_rotation.SetRotationY(atan2f(m_moveSpeed.x, m_moveSpeed.z));
		}
		m_position += m_moveSpeed;
		break;
	case enState_Dead:
		m_scale *= 0.9f;
		break;
	}
	if (m_state != enState_Dead) {
		// 敵と衝突判定
		const auto& enemyList = inGame.GetEnemyList();
		for (const auto& enemy : enemyList) {
			const Vector3& pos = enemy->GetPosition();
			Vector3 diff = pos - m_position;
			if (diff.Length() < 50.0f) {
				m_state = enState_Dead;
			}
		}
	}
	if (oldState != m_state) {
		// 状態が切り替わったことをオブザーバーに通知する
		Notify(enEvent_ChangeState, m_state);
	}
	
	m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);
}

void Player::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
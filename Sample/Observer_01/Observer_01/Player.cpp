#include "stdafx.h"
#include "Player.h"
#include "InGame.h"

Player::Player()
{
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
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
	}
	if (oldState != m_state) {
		// 状態が切り替わったことをオブザーバーに通知する
		Notify(enEvent_ChangeState, m_state);
	}
	
	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}

void Player::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
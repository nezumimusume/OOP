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
			// �W�����v����B
			// ��Ɉړ����鑬�x��ݒ肷��B
			m_moveSpeed.y = 20.0f;
			m_state = enState_Jump;
		}
		break;
	case enState_Jump:
		// �W�����v���B
		// �d�͉����x���ړ����x��Y�����ɉ�����B
		m_moveSpeed.y -= 1.5f;
		// ���W�Ɉړ����x�����Z����B
		m_position += m_moveSpeed;
		if ( m_position.y < 0.0f ) {
			m_position.y = 0.0f;
			// �n�ʂɂ����̂ŁA�ҋ@��ԂɑJ�ڂ���B
			m_state = enState_Idle;
		}
		break;
	}
	if (oldState != m_state) {
		// ��Ԃ��؂�ւ�������Ƃ��I�u�U�[�o�[�ɒʒm����
		Notify(enEvent_ChangeState, m_state);
	}
	
	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}

void Player::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
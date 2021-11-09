#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include <random>

Enemy::Enemy(Player& player, const int mapTbl[NUM_GRID_Z][NUM_GRID_X]) :
	m_player(player),
	m_mapTbl(mapTbl)
{
	// �v���C���[�̊Ď��҂Ƃ��ēo�^�B
	m_eventListener = m_player.AddEventListener([&](int event, int arg_0) {
		OnPlayerEvent(event, arg_0);
	});
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/enemy/enemy.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
	// �������W�����߂�B
	std::random_device rnd;
	int gridNoX = rnd() % NUM_GRID_X;
	int gridNoZ = rnd() % NUM_GRID_Z;
	m_position.x = gridNoX * GRID_SIZE + GRID_SIZE * 0.5f;
	m_position.z = gridNoZ * GRID_SIZE + GRID_SIZE * 0.5f;
	m_position.y = 1000.0f;
	m_state = enState_Fall;
}

Enemy::~Enemy()
{
	m_player.RemoveEventListener(m_eventListener);
}

void Enemy::OnPlayerEvent(int event, int arg_0)
{
	// ���b�Z�[�W�𑗂��Ă����̂��v���C���[�B
	if (event == Player::enEvent_ChangeState) {
		if (m_state != enState_Fall) {
			if (arg_0 == Player::enState_Move) {
				// �v���C���[�ɘA�����ē����B
				m_state = enState_Move;

			}
			else if (arg_0 == Player::enState_Idle) {
				// �v���C���[�ɘA�����Ď~�܂�B
				m_state = enState_Idle;
			}
		}
	}
}
bool Enemy::Update()
{
	switch (m_state) {
	case enState_Fall: {
		m_position.y -= 2.0f;
		m_rotation.AddRotationY(0.1f);
		if (m_position.y < 0.0f) {
			if (m_position.y < -300.0f) {
				// ���S�B
				m_state = enState_Dead;
			}
			// �n�ʂ��`�F�b�N
			int gridNoX = static_cast<int>(m_position.x / GRID_SIZE);
			int gridNoZ = static_cast<int>(m_position.z / GRID_SIZE);
			if (m_mapTbl[gridNoZ][gridNoX] == 0) {
				// ��
				m_rotation = g_quatIdentity;
				m_position.y = 0.0f;
				m_state = enState_Idle;
			}
		}
	}break;
	case enState_Move: {
		Vector3 toPlayerDir = m_player.GetPosition() - m_position;
		toPlayerDir.Normalize();
		m_position += toPlayerDir * 5.0f;
		m_rotation.SetRotationY(atan2f(toPlayerDir.x, toPlayerDir.z));
		// �����`�F�b�N
		int gridNoX = m_position.x / GRID_SIZE;
		int gridNoZ = m_position.z / GRID_SIZE;
		if (m_mapTbl[gridNoZ][gridNoX] == 1) {
			// ���Ƃ���
			m_state = enState_Fall;
		}
	}break;
	case enState_Idle:
		break;
	}
	m_model.UpdateWorldMatrix(m_position, m_rotation, {2.5f, 2.5f, 2.5f});
	return m_state != enState_Dead;
}
void Enemy::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
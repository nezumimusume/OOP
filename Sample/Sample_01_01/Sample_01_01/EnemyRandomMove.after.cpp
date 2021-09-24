#include "stdafx.h"
#include <random>
#include "EnemyRandomMove.h"

// step-2 �G�L�����N�^�[�̃����_���ړ��N���X�̒�`����������B
void EnemyRandomMove::Execute(Vector3& pos)
{
    // �����_���Ɉړ����x������B
	if (m_moveTimer % 120 == 0) {
		// 120�t���[���ňړ�������ύX����B
		std::random_device rd;
		m_moveSpeed.x = (rd() % 100) / 100.0f;
		m_moveSpeed.x -= 0.5f;
		m_moveSpeed.z = (rd() % 100) / 100.0f;
		m_moveSpeed.z -= 0.5f;
		// ���K������B
		m_moveSpeed.Normalize();
		// �ړ����x��0.3�B
		m_moveSpeed *= 0.3f;
	}
	// �ړ��^�C�}�[���C���N�������g
	m_moveTimer++;
	// �ړ����x�����W�ɉ��Z�B
	pos += m_moveSpeed;
}

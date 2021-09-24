#include "stdafx.h"
#include "Enemy.before.h"
#include <random>

Enemy::Enemy()
{
	// ���f���`�揈�����������B
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/enemy/enemy.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
}
/// <summary>
/// ���t���[���Ă΂��X�V�����B
/// </summary>
void Enemy::Update()
{
	// point-2 �����_���ړ��Ɋւ��鏈��
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
	m_position += m_moveSpeed;
	// point-2 �����܂�

	// ���[���h�s����X�V�B
	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}
/// <summary>
/// ���t���[���Ă΂��`�揈���B
/// </summary>
/// <param name="rc"></param>
void Enemy::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
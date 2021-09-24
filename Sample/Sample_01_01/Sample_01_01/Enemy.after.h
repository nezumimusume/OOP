#pragma once

#include "EnemyRandomMove.h"

/// <summary>
/// �G�l�~�[�N���X�B
/// </summary>
class Enemy
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Enemy();
	/// <summary>
	/// ���t���[���Ă΂��X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// ���t���[���Ă΂��`�揈���B
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
private:
	// step-3 �����_���ړ������̃C���X�^���X��Enemy�N���X�̃����o�ϐ��ɒǉ��B
	EnemyRandomMove m_randomMove; // �����_���ړ������B
	
	Vector3 m_position;		// ���W�B
	Model m_model;			// 3D���f���`�揈���B
	
};


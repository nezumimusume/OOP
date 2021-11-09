#pragma once

#include "Observer.h"

class Player;

/// <summary>
/// �G�N���X�B
/// </summary>
class Enemy : public Observer
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="player">�v���C���[</param>
	Enemy(Player& player);
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Enemy();
	/// <summary>
	/// �Ď����Ă���T�u�W�F�N�g�ŃC�x���g�����������Ƃ��ɌĂ΂�鏈���B
	/// </summary>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
private:
	enum EnState {
		enState_Idle,
		enState_Move,
		enState_Dead,
	};
	EnState m_state = enState_Idle;		// ��ԁB
	Model m_model;							// ���f���`�揈���B
	Vector3 m_position;						// ���W�B
	Player& m_player;							// �v���C���[�B
};


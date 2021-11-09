#pragma once

#include "Player.h"

/// <summary>
/// �G�N���X�B
/// </summary>
class Enemy
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="player">�v���C���[</param>
	Enemy(Player& player, const int (*mapTbl)[NUM_GRID_X]);
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Enemy();
	/// <summary>
	/// �v���C���[�ŃC�x���g�����������Ƃ��ɌĂ΂�鏈��
	/// </summary>
	void OnPlayerEvent(int event, int arg_0) ;
	/// <summary>
	/// �X�V����
	/// </summary>
	bool Update();
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
	/// <summary>
	/// ���W���擾
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
private:
	enum EnState {
		enState_Idle,
		enState_Move,
		enState_Fall,
		enState_Dead,
	};
	EnState m_state = enState_Idle;			// ��ԁB
	Model m_model;							// ���f���`�揈���B
	Vector3 m_position;						// ���W�B
	Player& m_player;						// �v���C���[�B
	Quaternion m_rotation;					// ��]�N�H�[�^�j�I���B
	int m_life = 240;						// ����
	Player::EventListener* m_eventListener = nullptr;
	const int  (*m_mapTbl)[NUM_GRID_X];
};


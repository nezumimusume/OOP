#pragma once
#include "Subject.h"

class InGame;

class Player : public Subject
{
public:
	/// <summary>
	/// �C�x���g
	/// </summary>
	enum EnEvent {
		enEvent_ChangeState,	// ��Ԃ��؂�ւ�����B
	};
	/// <summary>
	/// ���
	/// </summary>
	enum EnState {
		enState_Idle,
		enState_Jump,
		enState_Dead,
		enState_Move,
		enState_Num,
	};
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update(InGame& inGame);
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="rc">�����_�����O�R���e�L�X�g</param>
	void Draw(RenderContext& rc);
	/// <summary>
	/// ���W���擾�B
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}

private:
	
	EnState m_state = enState_Idle;		// ��ԁB
	Model m_model;							// ���f���`�揈���B
	Vector3 m_position;						// ���W�B
	Quaternion m_rotation;					// ��]�N�H�[�^�j�I���B
	Vector3 m_moveSpeed;					// �ړ����x�B
	Vector3 m_scale = g_vec3One;			// �g�嗦�B
};


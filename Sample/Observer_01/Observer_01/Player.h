#pragma once
#include "Subject.h"

class InGame;

class Player : public Subject
{
public:
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
	
private:
	/// <summary>
	/// ���
	/// </summary>
	enum EnState {
		enState_Idle,
		enState_Jump,
		enState_Num,
	};
	EnState m_state = enState_Idle;		// ��ԁB
	Model m_model;							// ���f���`�揈���B
	Vector3 m_position;						// ���W�B
	Vector3 m_moveSpeed;					//	�ړ����x�B
};


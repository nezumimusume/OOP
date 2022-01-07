#pragma once

#include "IGameObject.h"

// step-3 �Q�[���I�u�W�F�N�g���p�������X�P���g���N���X��錾����B
class Skeleton : public IGameObject
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	/// <param name="no">�X�P���g���̔ԍ�</param>
	Skeleton(int no);
	/// <summary>
	/// ���t���[���Ă΂��X�V�����B
	/// </summary>
	/// <param name="arg"></param>
	void Update(const UpdateArg& arg) override;
private:
	float m_shoutTimer = 0.0f;	// ���у^�C�}�[
	float m_deathTimer = 0.0f;	// ���S�^�C�}�[�B
	int m_no = 0;				// �X�P���g���ԍ��B
};


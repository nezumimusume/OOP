#pragma once

// step-1 IGameObject���p�����āA�C���Q�[���̏����𐧌䂷��N���X��錾����B

#include "IGameObject.h"

// �C���Q�[���N���X�B
class InGame : public IGameObject
{
public:
	/// <summary>
	/// ���t���[���Ă΂��X�V����
	/// </summary>
	void Update(const UpdateArg& arg) override;
private:
	float m_spawnTimer = 0.0f;		// �G�L�����N�^�[�̃X�|�[���^�C�}�[�B(�P��:�b)
	int m_spawnSkeletonCount = 0;	// �X�|�[�������X�P���g���̐��B
};


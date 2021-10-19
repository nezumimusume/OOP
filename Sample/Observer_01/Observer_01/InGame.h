#pragma once

#include "Player.h"
#include "Ground.h"

class InGame
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	InGame();
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~InGame();
	/// <summary>
	/// �X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈���B
	/// </summary>
	void Draw(RenderContext& rc);
	/// <summary>
	/// �C���X�^���X���擾�B
	/// </summary>
	/// <returns></returns>
	static InGame& GetInstance()
	{
		return *m_instance;
	}
	/// <summary>
	/// �v���C���[�̃C���X�^���X���擾�B
	/// </summary>
	/// <returns></returns>
	Player& GetPlayer()
	{
		return m_player;
	}
private:
	// step-1 �B��̃C���X�^���X���L�����邽�߂�static�����o�ϐ���錾����B
	static InGame* m_instance;	// �B��̃C���X�^���X�B

	Player m_player;			// �v���C���[
	Ground m_ground;			// �n��
};


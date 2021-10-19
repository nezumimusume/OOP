#pragma once

#include "Player.h"
#include "Ground.h"
#include "Achievement.h"

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
private:
	// �B��̃C���X�^���X���L�����邽�߂�static�����o�ϐ���錾����B
	static InGame* m_instance;	// �B��̃C���X�^���X�B
	Player m_player;			// �v���C���[
	Achievement m_achivement;	// ����
	Ground m_ground;			// �n��
};


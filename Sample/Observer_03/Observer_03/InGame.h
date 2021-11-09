#pragma once

#include "Player.h"
#include "Ground.h"
#include "Achievement.h"

class Enemy;

class InGame : public Observer
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
	/// �Ď����Ă���T�u�W�F�N�g���烁�b�Z�[�W������ꂽ���̏����B
	/// </summary>
	/// <param name="pSubject"></param>
	/// <param name="event"></param>
	/// <param name="arg_0"></param>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
private:
	// �B��̃C���X�^���X���L�����邽�߂�static�����o�ϐ���錾����B
	static InGame* m_instance;		// �B��̃C���X�^���X�B
	Player m_player;						// �v���C���[
	Enemy* m_enemy = nullptr;		// �G�l�~�[���X�g
	Achievement m_achivement;		// ����
	Ground m_ground;					// �n��
	int m_enemyPopTimer = 0;			// �G�l�~�[���|�b�v������^�C�}�[�B
};


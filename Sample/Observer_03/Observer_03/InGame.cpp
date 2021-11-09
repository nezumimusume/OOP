#include "stdafx.h"
#include "InGame.h"
#include "Enemy.h"

InGame* InGame::m_instance = nullptr;

InGame::InGame() :
	m_achivement(m_player)
{
	if (m_instance != nullptr) {
		MessageBox(nullptr, L"InGame�N���X�̃C���X�^���X����������Ă��܂��I", L"�G���[", MB_OK);
		std::abort();
	}

	m_player.AddObserver(this);
	// �C���X�^���X�̃A�h���X���L������B
	m_instance = this;
}

InGame::~InGame()
{
	m_instance = nullptr;
}

void InGame::Update()
{
	// �v���C���[�̍X�V�������Ăяo���B
	m_player.Update(*this);

	m_enemyPopTimer++;
	if (m_enemyPopTimer == 120) {
		// �Â��G�l�~�[���폜
		delete m_enemy;
		m_enemy = new Enemy(m_player);
		m_enemyPopTimer = 0;

	}
}
void InGame::OnNotify(Subject* pSubject, int event, int arg_0)
{
	if (&m_player == pSubject) {
		// ���b�Z�[�W�𑗂��Ă����̂��v���C���[�B
		if (event == Player::enEvent_ChangeState) {
			if (arg_0 == Player::enState_Dead) {
				MessageBoxA( nullptr, "�Q�[���I�[�o�[", "�ʒm", MB_OK );
			}
		}
	}
	
}
void InGame::Draw(RenderContext& rc)
{
	// �v���C���[�ƒn�ʂ̕`�揈�����Ăяo���B
	m_player.Draw(rc);
	m_ground.Draw(rc);
}
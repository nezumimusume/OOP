#include "stdafx.h"
#include "InGame.h"


InGame* InGame::m_instance = nullptr;

InGame::InGame() :
	m_achivement(m_player)
{
	if (m_instance != nullptr) {
		MessageBox(nullptr, L"InGame�N���X�̃C���X�^���X����������Ă��܂��I", L"�G���[", MB_OK);
		std::abort();
	}
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
}

void InGame::Draw(RenderContext& rc)
{
	// �v���C���[�ƒn�ʂ̕`�揈�����Ăяo���B
	m_player.Draw(rc);
	m_ground.Draw(rc);
}
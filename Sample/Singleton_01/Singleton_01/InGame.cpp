#include "stdafx.h"
#include "InGame.h"


// step-2 static�����o�ϐ����`����B


InGame::InGame()
{
	// step-3 �C���X�^���X�̐�����}������B

}

InGame::~InGame()
{
	// step-4 �C���X�^���X�̃A�h���X�̋L�����N���A����B

}

void InGame::Update()
{
	// �v���C���[�̍X�V�������Ăяo���B
	m_player.Update();
}

void InGame::Draw(RenderContext& rc)
{
	// �v���C���[�ƒn�ʂ̕`�揈�����Ăяo���B
	m_player.Draw(rc);
	m_ground.Draw(rc);
}
#include "stdafx.h"
#include "InGame.h"


// step-2 static�����o�ϐ����`����B
// C++�͐錾�_���ł�NG�Œ�`���p�ӂ���K�v������B
// �C���X�^���X�̐����}���̂��߂ɂ́Anullptr�ŏ���������̂��d�v�B
InGame* InGame::m_instance = nullptr;

InGame::InGame()
{
	// step-3 �C���X�^���X�̐�����}������B
	if (m_instance != nullptr) {
		// m_instance�̒l��nullptr�ł͂Ȃ��Ƃ������Ƃ́A
		// ���łɃC���X�^���X���쐬����Ă���Ƃ������ƂɂȂ�B
		MessageBox(nullptr, L"InGame�N���X�̃C���X�^���X����������Ă��܂��I", L"�G���[", MB_OK);
		std::abort();
	}
	// �C���X�^���X�̃A�h���X���L������B
	m_instance = this;
}

InGame::~InGame()
{
	// step-4 �C���X�^���X�̃A�h���X�̋L�����N���A����B
	// �C���X�^���X���j�����ꂽ�̂ŁAm_instance��nullptr��������B
	m_instance = nullptr;
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
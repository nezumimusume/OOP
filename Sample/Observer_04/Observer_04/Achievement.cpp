#include "stdafx.h"
#include "Achievement.h"
#include "InGame.h"

Achievement::Achievement(Player& player)
{
	m_player = &player;
	// �v���C���[�̏�ԕω����Ď�����B
	m_eventListener = m_player->AddEventListener([&](int event, int arg_0) {
		OnPlayerEvent(event, arg_0);
	});
}
Achievement::~Achievement()
{
	// �v���C���[�̏�ԕω��̊Ď�����߂�B
	m_player->RemoveEventListener(m_eventListener);
}
void Achievement::OnPlayerEvent(int event, int arg_0)
{
	if (event == Player::enEvent_ChangeState) {
		// �v���C���[�̏�Ԃ��ω������B
		if (arg_0 == Player::enState_Jump) {
			if (m_jumpCount == 0) {
				// ���߂ẴW�����v
				MessageBoxA(nullptr, "���߂ẴW�����v", "���щ���", MB_OK);
			}
			// �W�����v�̉񐔂��J�E���g�A�b�v�B
			m_jumpCount++;
		}
	}
}
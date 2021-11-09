#include "stdafx.h"
#include "Achievement.h"
#include "InGame.h"

Achievement::Achievement(Player& player)
{
	m_player = &player;
	// �v���C���[�̏�ԕω����Ď�����B
	m_player->AddObserver(this);
}
Achievement::~Achievement()
{
	// �v���C���[�̏�ԕω��̊Ď�����߂�B
	m_player->RemoveObserver(this);
}
void Achievement::OnNotify(Subject* pSubject, int event, int arg_0)
{
	if (m_player == pSubject) {
		// ���b�Z�[�W�𑗂��Ă����̂��v���C���[�B
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
}
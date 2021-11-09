#include "stdafx.h"
#include "Achievement.h"
#include "InGame.h"

Achievement::Achievement(Player& player)
{
	m_player = &player;
	// プレイヤーの状態変化を監視する。
	m_eventListener = m_player->AddEventListener([&](int event, int arg_0) {
		OnPlayerEvent(event, arg_0);
	});
}
Achievement::~Achievement()
{
	// プレイヤーの状態変化の監視をやめる。
	m_player->RemoveEventListener(m_eventListener);
}
void Achievement::OnPlayerEvent(int event, int arg_0)
{
	if (event == Player::enEvent_ChangeState) {
		// プレイヤーの状態が変化した。
		if (arg_0 == Player::enState_Jump) {
			if (m_jumpCount == 0) {
				// 初めてのジャンプ
				MessageBoxA(nullptr, "初めてのジャンプ", "実績解除", MB_OK);
			}
			// ジャンプの回数をカウントアップ。
			m_jumpCount++;
		}
	}
}
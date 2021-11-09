#include "stdafx.h"
#include "InGame.h"
#include "Enemy.h"

InGame* InGame::m_instance = nullptr;

InGame::InGame() :
	m_achivement(m_player)
{
	if (m_instance != nullptr) {
		MessageBox(nullptr, L"InGameクラスのインスタンスが複数作られています！", L"エラー", MB_OK);
		std::abort();
	}

	m_player.AddObserver(this);
	// インスタンスのアドレスを記憶する。
	m_instance = this;
}

InGame::~InGame()
{
	m_instance = nullptr;
}

void InGame::Update()
{
	// プレイヤーの更新処理を呼び出す。
	m_player.Update(*this);

	m_enemyPopTimer++;
	if (m_enemyPopTimer == 120) {
		// 古いエネミーを削除
		delete m_enemy;
		m_enemy = new Enemy(m_player);
		m_enemyPopTimer = 0;

	}
}
void InGame::OnNotify(Subject* pSubject, int event, int arg_0)
{
	if (&m_player == pSubject) {
		// メッセージを送ってきたのがプレイヤー。
		if (event == Player::enEvent_ChangeState) {
			if (arg_0 == Player::enState_Dead) {
				MessageBoxA( nullptr, "ゲームオーバー", "通知", MB_OK );
			}
		}
	}
	
}
void InGame::Draw(RenderContext& rc)
{
	// プレイヤーと地面の描画処理を呼び出す。
	m_player.Draw(rc);
	m_ground.Draw(rc);
}
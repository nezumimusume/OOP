#include "stdafx.h"
#include "InGame.h"
#include "Enemy.h"

// マップテーブル
static constexpr int MAP_TBL[NUM_GRID_Z][NUM_GRID_X] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};
InGame* InGame::m_instance = nullptr;

InGame::InGame() :
	m_achivement(m_player)
{
	if (m_instance != nullptr) {
		MessageBox(nullptr, L"InGameクラスのインスタンスが複数作られています！", L"エラー", MB_OK);
		std::abort();
	}

	g_camera3D->SetPosition(1000.0f, 500.0f, 1500.0f);
	g_camera3D->SetTarget(1000.0f, 0.0f, 1000.0f);
	// プレイヤーの状態変化を監視する。
	m_player.AddEventListener([&](int event, int arg_0) {
		OnPlayerEvent(event, arg_0);
	});
	// インスタンスのアドレスを記憶する。
	m_instance = this;
}

InGame::~InGame()
{
	m_instance = nullptr;
	for (Enemy* en : m_enemyList) {
		delete en;
	}
}

void InGame::Update()
{
	// プレイヤーの更新処理を呼び出す。
	m_player.Update(*this);

	if (m_enemyList.size() < 40) {
		m_enemyPopTimer++;
		if (m_enemyPopTimer == 140) {
			// 古いエネミーを削除
			//delete m_enemy;
			Enemy* newEnemy = new Enemy(m_player, MAP_TBL);
			m_enemyList.push_back(newEnemy);
			m_enemyPopTimer = 0;
		}
	}
	auto it = m_enemyList.begin();
	while( it != m_enemyList.end()){
		if ((*it)->Update() == false) {
			delete* it;
			it = m_enemyList.erase( it );
			
		}
		else {
			it++;
		}
	}
}
void InGame::OnPlayerEvent( int event, int arg_0)
{
	// メッセージを送ってきたのがプレイヤー。
	if (event == Player::enEvent_ChangeState) {
		if (arg_0 == Player::enState_Dead) {
			MessageBoxA( nullptr, "ゲームオーバー", "通知", MB_OK );
		}
	}
}
void InGame::Draw(RenderContext& rc)
{
	// プレイヤーと地面の描画処理を呼び出す。
	m_player.Draw(rc);
	m_ground.Draw(rc);
	for (Enemy* en : m_enemyList) {
		en->Draw(rc);
	}
}
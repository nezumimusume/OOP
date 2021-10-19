#include "stdafx.h"
#include "InGame.h"


InGame* InGame::m_instance = nullptr;

InGame::InGame()
{
	if (m_instance != nullptr) {
		MessageBox(nullptr, L"InGameクラスのインスタンスが複数作られています！", L"エラー", MB_OK);
		std::abort();
	}
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
	m_player.Update();
}

void InGame::Draw(RenderContext& rc)
{
	// プレイヤーと地面の描画処理を呼び出す。
	m_player.Draw(rc);
	m_ground.Draw(rc);
}
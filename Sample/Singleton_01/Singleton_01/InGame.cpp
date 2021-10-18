#include "stdafx.h"
#include "InGame.h"


// step-2 staticメンバ変数を定義する。


InGame::InGame()
{
	// step-3 インスタンスの生成を抑制する。

}

InGame::~InGame()
{
	// step-4 インスタンスのアドレスの記憶をクリアする。

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
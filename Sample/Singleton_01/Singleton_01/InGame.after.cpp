#include "stdafx.h"
#include "InGame.h"


// step-2 staticメンバ変数を定義する。
// C++は宣言ダメではNGで定義も用意する必要がある。
// インスタンスの生成抑制のためには、nullptrで初期化するのが重要。
InGame* InGame::m_instance = nullptr;

InGame::InGame()
{
	// step-3 インスタンスの生成を抑制する。
	if (m_instance != nullptr) {
		// m_instanceの値がnullptrではないということは、
		// すでにインスタンスが作成されているということになる。
		MessageBox(nullptr, L"InGameクラスのインスタンスが複数作られています！", L"エラー", MB_OK);
		std::abort();
	}
	// インスタンスのアドレスを記憶する。
	m_instance = this;
}

InGame::~InGame()
{
	// step-4 インスタンスのアドレスの記憶をクリアする。
	// インスタンスが破棄されたので、m_instanceにnullptrを代入する。
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
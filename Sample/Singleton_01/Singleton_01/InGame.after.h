#pragma once

#include "Player.h"
#include "Ground.h"

class InGame
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	InGame();
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~InGame();
	/// <summary>
	/// 更新処理。
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理。
	/// </summary>
	void Draw(RenderContext& rc);
private:
	// step-1 唯一のインスタンスを記憶するためのstaticメンバ変数を宣言する。
	static InGame* m_instance;	// 唯一のインスタンス。

	Player m_player;			// プレイヤー
	Ground m_ground;			// 地面
};


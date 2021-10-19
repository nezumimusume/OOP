#pragma once

#include "Player.h"
#include "Ground.h"
#include "Achievement.h"

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
	// 唯一のインスタンスを記憶するためのstaticメンバ変数を宣言する。
	static InGame* m_instance;	// 唯一のインスタンス。
	Player m_player;			// プレイヤー
	Achievement m_achivement;	// 実績
	Ground m_ground;			// 地面
};


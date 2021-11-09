#pragma once

#include "Player.h"
#include "Ground.h"
#include "Achievement.h"

class Enemy;

class InGame : public Observer
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
	/// <summary>
	/// 監視しているサブジェクトからメッセージが送られた時の処理。
	/// </summary>
	/// <param name="pSubject"></param>
	/// <param name="event"></param>
	/// <param name="arg_0"></param>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
private:
	// 唯一のインスタンスを記憶するためのstaticメンバ変数を宣言する。
	static InGame* m_instance;		// 唯一のインスタンス。
	Player m_player;						// プレイヤー
	Enemy* m_enemy = nullptr;		// エネミーリスト
	Achievement m_achivement;		// 実績
	Ground m_ground;					// 地面
	int m_enemyPopTimer = 0;			// エネミーをポップさせるタイマー。
};


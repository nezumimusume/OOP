#pragma once

#include "Observer.h"

class Player;

/// <summary>
/// 敵クラス。
/// </summary>
class Enemy : public Observer
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="player">プレイヤー</param>
	Enemy(Player& player);
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Enemy();
	/// <summary>
	/// 監視しているサブジェクトでイベントが発生したときに呼ばれる処理。
	/// </summary>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
private:
	enum EnState {
		enState_Idle,
		enState_Move,
		enState_Dead,
	};
	EnState m_state = enState_Idle;		// 状態。
	Model m_model;							// モデル描画処理。
	Vector3 m_position;						// 座標。
	Player& m_player;							// プレイヤー。
};


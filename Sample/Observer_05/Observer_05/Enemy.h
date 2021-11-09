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
	Enemy(Player& player, const int (*mapTbl)[NUM_GRID_X]);
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Enemy();
	/// <summary>
	/// 監視しているサブジェクトでイベントが発生したときに呼ばれる処理。
	/// </summary>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
	/// <summary>
	/// 更新処理
	/// </summary>
	bool Update();
	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
	/// <summary>
	/// 座標を取得
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}
private:
	enum EnState {
		enState_Idle,
		enState_Move,
		enState_Fall,
		enState_Dead,
	};
	EnState m_state = enState_Idle;		// 状態。
	Model m_model;							// モデル描画処理。
	Vector3 m_position;						// 座標。
	Player& m_player;							// プレイヤー。
	Quaternion m_rotation;					// 回転クォータニオン。
	int m_life = 240;							// 寿命
	const int  (*m_mapTbl)[NUM_GRID_X];
};


#pragma once
#include "Subject.h"

class InGame;

class Player : public Subject
{
public:
	/// <summary>
	/// イベント
	/// </summary>
	enum EnEvent {
		enEvent_ChangeState,	// 状態が切り替わった。
	};
	/// <summary>
	/// 状態
	/// </summary>
	enum EnState {
		enState_Idle,
		enState_Jump,
		enState_Dead,
		enState_Move,
		enState_Num,
	};
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update(InGame& inGame);
	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="rc">レンダリングコンテキスト</param>
	void Draw(RenderContext& rc);
	/// <summary>
	/// 座標を取得。
	/// </summary>
	/// <returns></returns>
	const Vector3& GetPosition() const
	{
		return m_position;
	}

private:
	
	EnState m_state = enState_Idle;		// 状態。
	Model m_model;							// モデル描画処理。
	Vector3 m_position;						// 座標。
	Quaternion m_rotation;					// 回転クォータニオン。
	Vector3 m_moveSpeed;					// 移動速度。
	Vector3 m_scale = g_vec3One;			// 拡大率。
};


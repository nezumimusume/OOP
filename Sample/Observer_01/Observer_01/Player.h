#pragma once
#include "Subject.h"

class InGame;

class Player : public Subject
{
public:
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
	
private:
	/// <summary>
	/// 状態
	/// </summary>
	enum EnState {
		enState_Idle,
		enState_Jump,
		enState_Num,
	};
	EnState m_state = enState_Idle;		// 状態。
	Model m_model;							// モデル描画処理。
	Vector3 m_position;						// 座標。
	Vector3 m_moveSpeed;					//	移動速度。
};


#pragma once

#include "IGameObject.h"
class Skeleton : public IGameObject
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Skeleton(int no);
	/// <summary>
	/// 毎フレーム呼ばれる更新処理。
	/// </summary>
	/// <param name="arg"></param>
	void Update(const UpdateArg& arg) override;
private:
	float m_shoutTimer = 0.0f;	// 叫びタイマー
	float m_deathTimer = 0.0f;	// 死亡タイマー。
	int m_no = 0;				// スケルトン番号。
};


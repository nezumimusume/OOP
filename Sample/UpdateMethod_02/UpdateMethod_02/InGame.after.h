#pragma once

// step-1 IGameObjectを継承して、インゲームの処理を制御するクラスを宣言する。

#include "IGameObject.h"

// インゲームクラス。
class InGame : public IGameObject
{
public:
	/// <summary>
	/// 毎フレーム呼ばれる更新処理
	/// </summary>
	void Update(const UpdateArg& arg) override;
private:
	float m_spawnTimer = 0.0f;		// 敵キャラクターのスポーンタイマー。(単位:秒)
	int m_spawnSkeletonCount = 0;	// スポーンしたスケルトンの数。
};


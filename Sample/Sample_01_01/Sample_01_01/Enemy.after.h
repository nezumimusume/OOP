#pragma once

#include "EnemyRandomMove.h"

/// <summary>
/// エネミークラス。
/// </summary>
class Enemy
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Enemy();
	/// <summary>
	/// 毎フレーム呼ばれる更新処理。
	/// </summary>
	void Update();
	/// <summary>
	/// 毎フレーム呼ばれる描画処理。
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
private:
	// step-3 ランダム移動処理のインスタンスをEnemyクラスのメンバ変数に追加。
	EnemyRandomMove m_randomMove; // ランダム移動処理。
	
	Vector3 m_position;		// 座標。
	Model m_model;			// 3Dモデル描画処理。
	
};


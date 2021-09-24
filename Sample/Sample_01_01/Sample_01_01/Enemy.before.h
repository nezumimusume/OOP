#pragma once
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
	// point-1 移動処理に関するメンバ変数
	Vector3 m_moveSpeed;	// 移動速度。
	int m_moveTimer = 0;	// 移動タイマー。
	// point-1 ここまで

	Vector3 m_position;		// 座標。
	Model m_model;			// 3Dモデル描画処理。
	
};


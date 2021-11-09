#pragma once
class Ground
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Ground();
	/// <summary>
	/// 描画処理。
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
private:
	Model m_model;	// モデル描画処理。
};




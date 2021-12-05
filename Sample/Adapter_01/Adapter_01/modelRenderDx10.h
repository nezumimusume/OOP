#pragma once
class modelRenderDx10
{
public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	void initialyze();
	/// <summary>
	/// 描画の準備処理。
	/// </summary>
	void prepareDraw();
	/// <summary>
	/// 描画。
	/// </summary>
	void draw();
	/// <summary>
	/// 描画の終了処理
	/// </summary>
	void endDraw();
};


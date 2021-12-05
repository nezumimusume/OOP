#pragma once
/// <summary>
/// 3Dモデルを画面に表示するためのインターフェースを定義したクラス。
/// </summary>
class IModel
{
public:
	/// <summary>
	/// 初期化処理。
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// 描画開始時に呼び出す必要がある処理。
	/// </summary>
	virtual void BeginDraw() = 0;
	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// 描画終了時に呼び出す必要がある処理。
	/// </summary>
	virtual void EndDraw() = 0;
	
};


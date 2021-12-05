#pragma once
#include "IModel.h"

class ModelDx12 : public IModel
{
public:
	/// <summary>
	/// 初期化処理。
	/// </summary>
	void Init() override;
	/// <summary>
	/// 描画開始時に呼び出す必要がある処理。
	/// </summary>
	void BeginDraw() override;
	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;
	/// <summary>
	/// 描画終了時に呼び出す必要がある処理。
	/// </summary>
	void EndDraw() override;
};


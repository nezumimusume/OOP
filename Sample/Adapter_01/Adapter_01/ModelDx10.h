#pragma once
#include "IModel.h"
#include "modelRenderDx10.h"

// step-1 modelRenderDx10を利用するアダプタクラス宣言を作成する。
class ModelDx10 : public IModel
{
public:
	void Init() override;
	void BeginDraw() override;
	void Draw() override;
	void EndDraw() override;
private:
	modelRenderDx10 m_modelRenderDx10;	// 実装の詳細はmodelRenderDx10に委譲する。
};


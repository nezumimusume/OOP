#include "ModelDx10.h"

// step-2 modelRenderDx10を利用するアダプタクラス定義を作成する。

void ModelDx10::Init()
{
	// modelRenderDx10に委譲する
	m_modelRenderDx10.initialyze();
}
void ModelDx10::BeginDraw()
{
	// modelRenderDx10に委譲する
	m_modelRenderDx10.prepareDraw();
}
void ModelDx10::Draw()
{
	// modelRenderDx10に委譲する
	m_modelRenderDx10.draw();
}
void ModelDx10::EndDraw()
{
	// modelRenderDx10に委譲する
	m_modelRenderDx10.endDraw();
}
#include "stdafx.h"
#include "Ground.h"


Ground::Ground()
{
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/bg/bg.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
}

void Ground::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
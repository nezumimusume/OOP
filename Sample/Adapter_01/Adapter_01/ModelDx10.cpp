#include "ModelDx10.h"

// step-2 modelRenderDx10�𗘗p����A�_�v�^�N���X��`���쐬����B

void ModelDx10::Init()
{
	// modelRenderDx10�ɈϏ�����
	m_modelRenderDx10.initialyze();
}
void ModelDx10::BeginDraw()
{
	// modelRenderDx10�ɈϏ�����
	m_modelRenderDx10.prepareDraw();
}
void ModelDx10::Draw()
{
	// modelRenderDx10�ɈϏ�����
	m_modelRenderDx10.draw();
}
void ModelDx10::EndDraw()
{
	// modelRenderDx10�ɈϏ�����
	m_modelRenderDx10.endDraw();
}
#pragma once
#include "IModel.h"
#include "modelRenderDx10.h"

// step-1 modelRenderDx10�𗘗p����A�_�v�^�N���X�錾���쐬����B
class ModelDx10 : public IModel
{
public:
	void Init() override;
	void BeginDraw() override;
	void Draw() override;
	void EndDraw() override;
private:
	modelRenderDx10 m_modelRenderDx10;	// �����̏ڍׂ�modelRenderDx10�ɈϏ�����B
};


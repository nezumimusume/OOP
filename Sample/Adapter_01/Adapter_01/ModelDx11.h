#pragma once
#include "IModel.h"

/// <summary>
/// DirectX11�𗘗p�������f���\�������B
/// </summary>
class ModelDx11 : public IModel
{
public:
	/// <summary>
	/// �����������B
	/// </summary>
	void Init() override;
	/// <summary>
	/// �`��J�n���ɌĂяo���K�v�����鏈���B
	/// </summary>
	void BeginDraw() override;
	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw() override;
	/// <summary>
	/// �`��I�����ɌĂяo���K�v�����鏈���B
	/// </summary>
	void EndDraw() override;
};


#pragma once
/// <summary>
/// 3D���f������ʂɕ\�����邽�߂̃C���^�[�t�F�[�X���`�����N���X�B
/// </summary>
class IModel
{
public:
	/// <summary>
	/// �����������B
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// �`��J�n���ɌĂяo���K�v�����鏈���B
	/// </summary>
	virtual void BeginDraw() = 0;
	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// �`��I�����ɌĂяo���K�v�����鏈���B
	/// </summary>
	virtual void EndDraw() = 0;
	
};


#pragma once
class Ground
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Ground();
	/// <summary>
	/// �`�揈���B
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
private:
	Model m_model;	// ���f���`�揈���B
};




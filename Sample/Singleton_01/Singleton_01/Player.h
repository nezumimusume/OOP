#pragma once
class Player
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name="rc">�����_�����O�R���e�L�X�g</param>
	void Draw(RenderContext& rc);
	
private:
	Model m_model;		// ���f���`�揈���B
	Vector3 m_position;	// ���W�B
};


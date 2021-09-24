#pragma once
/// <summary>
/// �G�l�~�[�N���X�B
/// </summary>
class Enemy
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Enemy();
	/// <summary>
	/// ���t���[���Ă΂��X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// ���t���[���Ă΂��`�揈���B
	/// </summary>
	/// <param name="rc"></param>
	void Draw(RenderContext& rc);
private:
	// point-1 �ړ������Ɋւ��郁���o�ϐ�
	Vector3 m_moveSpeed;	// �ړ����x�B
	int m_moveTimer = 0;	// �ړ��^�C�}�[�B
	// point-1 �����܂�

	Vector3 m_position;		// ���W�B
	Model m_model;			// 3D���f���`�揈���B
	
};


#pragma once

// Enemy�N���X�̑O���錾
class Enemy;

// step-1 �G�L�����N�^�[�̃����_���ړ��N���X�̐錾����������B
class EnemyRandomMove {
public:
	// �ړ����������s����֐��B
	// �����Ɉړ���������W�̎Q�Ƃ��󂯎��B
	void Execute(Vector3& pos);
private:
	Vector3 m_moveSpeed;	// �y���ځz�ړ����x�B
	int m_moveTimer = 0;	// �y���ځz�ړ��^�C�}�[�B
};


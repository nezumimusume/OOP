#pragma once

/// <summary>
/// �G�l�~�[�̈ړ������̃C���^�[�t�F�[�X�N���X�B
/// </summary>
class IEnemyMove
{
public:
	virtual ~IEnemyMove() {}	
	/// <summary>
	/// �ړ����������s�B
	/// </summary>
	virtual void Execute() = 0;
};


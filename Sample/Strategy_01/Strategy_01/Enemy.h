#pragma once

#include "IEnemyMove.h"

class Enemy
{
public:
	
	/// <summary>
	/// �X�V�����B
	/// </summary>
	void Update();
	/// <summary>
	/// �ړ�������؂�ւ��B
	/// </summary>
	/// <param name="move"></param>
	void ChangeMove(IEnemyMove* move)
	{
		delete m_move;
		m_move = move;
	}
private:
	IEnemyMove* m_move = nullptr;	// �G�l�~�[�̈ړ������B
};


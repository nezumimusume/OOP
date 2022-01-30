#pragma once

#include "IEnemyMove.h"

class Enemy
{
public:
	
	/// <summary>
	/// 更新処理。
	/// </summary>
	void Update();
	/// <summary>
	/// 移動処理を切り替え。
	/// </summary>
	/// <param name="move"></param>
	void ChangeMove(IEnemyMove* move)
	{
		delete m_move;
		m_move = move;
	}
private:
	IEnemyMove* m_move = nullptr;	// エネミーの移動処理。
};


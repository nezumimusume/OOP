#pragma once

#include "IEnemyMove.h"
class EnemyMoveRandom : public IEnemyMove
{
public:
	/// <summary>
	/// 移動処理を実行。
	/// </summary>
	void Execute();
};


#pragma once

/// <summary>
/// エネミーの移動処理のインターフェースクラス。
/// </summary>
class IEnemyMove
{
public:
	virtual ~IEnemyMove() {}	
	/// <summary>
	/// 移動処理を実行。
	/// </summary>
	virtual void Execute() = 0;
};


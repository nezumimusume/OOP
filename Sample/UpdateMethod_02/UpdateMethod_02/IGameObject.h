#pragma once


class GameWorld;

/// <summary>
/// ゲームオブジェクトの基底クラス。
/// </summary>
class IGameObject
{
public:
	/// <summary>
	/// 更新関数に渡す引数。
	/// </summary>
	struct UpdateArg {
		GameWorld* world;		// ゲームワールド
		float frameDuration;	// 1フレームの間隔(単位:秒)。
	};
	/// <summary>
	/// 毎フレーム呼ばれる更新関数。
	/// </summary>
	virtual void Update(const UpdateArg& arg) = 0;
	/// <summary>
	/// 削除の印を付ける。
	/// </summary>
	void SetMarkDelete()
	{
		m_isDelete = true;
	}
	/// <summary>
	/// 削除の印がついている？
	/// </summary>
	/// <returns></returns>
	bool IsMarkDelete() const
	{
		return m_isDelete;
	}
private:
	bool m_isDelete = false;	// 削除フラグ。
};


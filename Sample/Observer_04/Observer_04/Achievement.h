#pragma once


#include "Player.h"

/// <summary>
/// 実績クラス
/// </summary>
class Achievement 
{
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	Achievement(Player& player);
	
	/// <summary>
	/// デストラクタ。
	/// </summary>
	~Achievement();
	/// <summary>
	/// 監視しているサブジェクトでイベントが発生したときに呼ばれる処理
	/// </summary>
	/// <param name="pSubject"></param>
	/// <param name="event"></param>
	/// <param name="arg_0"></param>
	void OnPlayerEvent(int event, int arg_0) ;
private:
	/// <summary>
	/// 実績の種類
	/// </summary>
	enum class EnAchivement {
		FIRST_JUMP,		// 初めてのジャンプ。
		FIVE_JUMP,		// ジャンプを５回した。
		NUM,			// 実績の数。
	};
	Player* m_player = nullptr;	// プレイヤー。
	Player::EventListener* m_eventListener = nullptr;
	int m_jumpCount = 0;
	bool m_isCompleted[(int)EnAchivement::NUM] = { false };	// 実績の達成フラグ。
};


#pragma once
#include "ITouch.h"

// step-2 iOS向けのタッチ状況取得クラス宣言を実装。
class TouchIOS : public ITouch
{
public:
	// タッチされた座標を取得。
	// x : x座標
	// y : y座標
	void GetTouchPosition(float& x, float& y) const override;
	// 画面がタッチされているか判定。
	// trueが返ってくるとタッチされている。
	bool IsPressTouch() const override;
};


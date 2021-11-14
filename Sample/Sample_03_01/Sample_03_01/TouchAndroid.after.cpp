#include <iostream>
#include "TouchAndroid.h"

// step-5 Android向けのタッチ状況取得クラス定義を実装。
void TouchAndroid::GetTouchPosition(float& x, float& y) const 
{
	std::cout << "Androidのタッチ座標取得処理\n";
	x = 10.0f;
	y = 20.0f;
}

bool TouchAndroid::IsPressTouch() const
{
	std::cout << "Androidのタッチ判定処理\n";
	return true;
}
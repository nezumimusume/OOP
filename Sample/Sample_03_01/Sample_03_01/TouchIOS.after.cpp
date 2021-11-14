#include <iostream>
#include "TouchIOS.h"

// step-3 iOS向けのタッチ状況取得クラス定義を実装。
void TouchIOS::GetTouchPosition(float& x, float& y) const
{
	std::cout << "iOSのタッチ座標取得処理\n";
	x = 10.0f;
	y = 20.0f;
}
bool TouchIOS::IsPressTouch() const
{
	std::cout << "iOSのタッチ判定処理\n";
	return true;
}
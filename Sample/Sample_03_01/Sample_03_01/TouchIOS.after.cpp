#include <iostream>
#include "TouchIOS.h"

// step-3 iOS�����̃^�b�`�󋵎擾�N���X��`�������B
void TouchIOS::GetTouchPosition(float& x, float& y) const
{
	std::cout << "iOS�̃^�b�`���W�擾����\n";
	x = 10.0f;
	y = 20.0f;
}
bool TouchIOS::IsPressTouch() const
{
	std::cout << "iOS�̃^�b�`���菈��\n";
	return true;
}
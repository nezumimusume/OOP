#include <iostream>
#include "TouchAndroid.h"

// step-5 Android�����̃^�b�`�󋵎擾�N���X��`�������B
void TouchAndroid::GetTouchPosition(float& x, float& y) const 
{
	std::cout << "Android�̃^�b�`���W�擾����\n";
	x = 10.0f;
	y = 20.0f;
}

bool TouchAndroid::IsPressTouch() const
{
	std::cout << "Android�̃^�b�`���菈��\n";
	return true;
}
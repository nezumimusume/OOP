#pragma once
#include "ITouch.h"

// step-2 iOS�����̃^�b�`�󋵎擾�N���X�錾�������B
class TouchIOS : public ITouch
{
public:
	// �^�b�`���ꂽ���W���擾�B
	// x : x���W
	// y : y���W
	void GetTouchPosition(float& x, float& y) const override;
	// ��ʂ��^�b�`����Ă��邩����B
	// true���Ԃ��Ă���ƃ^�b�`����Ă���B
	bool IsPressTouch() const override;
};


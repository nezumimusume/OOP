#pragma once

// step-1 �^�b�`�󋵂��擾���邽�߂̃C���^�[�t�F�[�X�N���X����������B
class ITouch
{
public:
	// �^�b�`���ꂽ���W���擾�B
	// x : x���W
	// y : y���W
	virtual void GetTouchPosition(float& x, float& y) const = 0;
	// ��ʂ��^�b�`����Ă��邩����B
	// true���Ԃ��Ă���ƃ^�b�`����Ă���B
	virtual bool IsPressTouch() const = 0;
};


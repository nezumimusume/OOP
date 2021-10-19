#pragma once

class Subject;

class Observer
{
public:
	/// <summary>
	/// �Ď����Ă���I�u�W�F�N�g����̒ʒm���b�Z�[�W���󂯎��֐��B
	/// </summary>
	/// <param name="pSubject">���b�Z�[�W�𑗂��Ă����T�u�W�F�N�g</param>
	/// <param name="event">�C�x���g</param>
	virtual void OnNotify( Subject* pSubject, int event ) = 0;
};


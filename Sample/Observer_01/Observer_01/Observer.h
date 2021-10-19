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
	/// <param name="arg_0"></param>
	virtual void OnNotify( Subject* pSubject, int event, int arg_0 ) = 0;
};


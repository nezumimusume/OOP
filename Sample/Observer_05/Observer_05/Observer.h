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
	/// <summary>
	/// ���̃I�u�U�[�o�[���擾�B
	/// </summary>
	/// <returns></returns>
	Observer* GetNext() const
	{
		return m_next;
	}
	/// <summary>
	/// ���̃I�u�U�[�o�[��ݒ�B
	/// </summary>
	/// <param name="next"></param>
	void SetNext(Observer* next)
	{
		m_next = next;
	}
private:
	Observer* m_next = nullptr;	// ���̃I�u�U�[�o�[�B
};


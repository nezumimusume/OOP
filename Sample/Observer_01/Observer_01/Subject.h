#pragma once

#include <algorithm>
#include "Observer.h"

/// <summary>
/// �Ď��Ώۖ��̃N���X�B
/// </summary>
class Subject
{
public:
	/// <summary>
	/// �I�u�U�[�o�[��ǉ�
	/// </summary>
	/// <param name="o">�I�u�U�[�o�[</param>
	void AddObserver(Observer* o)
	{
		//�@���łɓo�^����Ă���I�u�U�[�o�[��������Ȃ��̂ŁA
		//�@�܂��͂���𒲍�������B
		auto itFind = std::find(m_observerList.begin(),m_observerList.end(), o );
		if (itFind == m_observerList.end()) {
			// �C�e���[�^�[�̏I�[�܂ōs�����̂Ŗ��o�^�B
			// �ǉ�����B
			m_observerList.emplace_back(o);
		}
	}
	/// <summary>
	/// �I�u�U�[�o�[���폜
	/// </summary>
	/// <param name="o">�I�u�U�[�o�[</param>
	void RemoveObserver(Observer* o)
	{
		//�@�o�^����Ă���I�u�U�[�o�[�����ׂ�B
		auto itFind = std::find(m_observerList.begin(), m_observerList.end(), o);
		if (itFind != m_observerList.end()) {
			// �o�^����Ă���̂ō폜����B
			m_observerList.erase(itFind);
		}
	}
	/// <summary>
	/// �I�u�U�[�o�[�ɃC�x���g��ʒm����B
	/// </summary>
	/// <param name="event">�C�x���g</param>
	/// <param name="arg_0">����</param>
	void Notify(int event, int arg_0)
	{
		for (auto& o : m_observerList) {
			o->OnNotify( this, event, arg_0 );
		}
	}
private:
	std::list< Observer* > m_observerList;
};


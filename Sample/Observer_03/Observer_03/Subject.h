#pragma once

#include <algorithm>
#include "Observer.h"
#include "ObserverList.h"

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
		m_observerList.Add(o);
	}
	/// <summary>
	/// �I�u�U�[�o�[���폜
	/// </summary>
	/// <param name="o">�I�u�U�[�o�[</param>
	void RemoveObserver(Observer* o)
	{
		m_observerList.Remove(o);
	}
	/// <summary>
	/// �I�u�U�[�o�[�ɃC�x���g��ʒm����B
	/// </summary>
	/// <param name="event">�C�x���g</param>
	/// <param name="arg_0">����</param>
	void Notify(int event, int arg_0)
	{
		ObserverList::Node* node = m_observerList.GetTopNode();
		while (node != nullptr) {
			node->value->OnNotify(this, event, arg_0);
			node = node->nextNode;
		}
	}
private:
	ObserverList m_observerList;	// �I�u�U�[�o�[�̃��X�g�B
	
};


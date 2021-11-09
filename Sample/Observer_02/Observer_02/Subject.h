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
		if (m_observerHead == nullptr) {
			m_observerHead = o;
			m_observerHead->SetNext(nullptr);
		}
		//�@���łɓo�^����Ă��邩���ׂ�B
		bool isFind = false;
		Observer* oEnd = nullptr;
		Observer* oTmp = m_observerHead;
		while (oTmp != nullptr) {
			if (oTmp == o) {
				// ���łɒǉ�����Ă���B
				isFind = true;
				break;
			}
			oEnd = oTmp;
			oTmp = oTmp->GetNext();
		}
		if (isFind == false) {
			// ���X�g�̖����ɃI�u�U�[�o�[��A������B
			oEnd->SetNext(o);
			o->SetNext(nullptr);
		}
	}
	/// <summary>
	/// �I�u�U�[�o�[���폜
	/// </summary>
	/// <param name="o">�I�u�U�[�o�[</param>
	void RemoveObserver(Observer* o)
	{
		//�@�o�^���ꂩ���ׂ�
		Observer* oPrev = nullptr;
		Observer* oTmp = m_observerHead;
		while (oTmp != nullptr) {
			if (oTmp == o) {
				// �o�^����Ă����B
				if (oPrev == nullptr) {
					// �擪�̃I�u�U�[�o�[
					// �I�u�U�[�o�[�̐擪��ύX����B
					m_observerHead = o->GetNext();
				}
				else {
					// �Ԃ̃I�u�U�[�o�[�B
					// �����N�����ւ���B
					oPrev->SetNext(o->GetNext());
				}
				break;
			}
			oPrev = oTmp;
			oTmp = oTmp->GetNext();
		}
	}
	/// <summary>
	/// �I�u�U�[�o�[�ɃC�x���g��ʒm����B
	/// </summary>
	/// <param name="event">�C�x���g</param>
	/// <param name="arg_0">����</param>
	void Notify(int event, int arg_0)
	{
		Observer* o = m_observerHead;
		while (o != nullptr) {
			o->OnNotify(this, event, arg_0);
			o = o->GetNext();
		}
	}
private:
	Observer* m_observerHead = nullptr;
	
};


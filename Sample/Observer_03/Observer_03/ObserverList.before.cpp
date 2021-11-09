#include "stdafx.h"
#include "ObserverList.h"

ObserverList::ObserverList()
{
}
void ObserverList::Add(Observer* o)
{
	// �|�C���g�[�P �f�t�H���g�������A���P�[�^�[�ŐV�����m�[�h���m�ۂ��Ă���B
	Node* newNode = new Node;

	newNode->value = o;
	if (m_topNode == nullptr) {
		// ���X�g����
		m_topNode = newNode;
		m_tailNode = m_topNode;
	}
	else {
		// �󂶂�Ȃ���΁A�I�[�m�[�h��next�ɂȂ���B
		m_tailNode->nextNode = newNode;
	}
}
void ObserverList::Remove(Observer* o)
{
	Node* p = m_topNode;
	Node* prevNode = nullptr;
	while (p != nullptr) {
		if (p->value == o) {
			// �������B
			if (p == m_topNode) {
				// �擪�̃m�[�h
				if (m_topNode == m_tailNode) {
					// �擪�ƏI�[�������Ƃ������Ƃ͗v�f���P
					m_topNode = nullptr;
					m_tailNode = nullptr;
				}
				else {
					// �����̗v�f���L������Ă���B
					m_topNode = p->nextNode;
				}
			}
			else if (p == m_tailNode) {
				// �I�[�m�[�h�B
				m_tailNode = prevNode;
			}
			else {
				// �Ԃ̃m�[�h�B
				prevNode->nextNode = p->nextNode;
			}
			// �|�C���g-2 �f�t�H���g�̃J�X�^���������A���P�[�^�[�Ƀ�������ԋp����B
			delete p;
			
			break;
		}
		prevNode = p;
		p = p->nextNode;
	}
}

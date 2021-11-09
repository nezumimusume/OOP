#include "stdafx.h"
#include "ObserverList.h"

ObserverList::ObserverList()
{
	// step-3 �J�X�^���A���P�[�^�[�p�̃����o������������B
	
}
void ObserverList::Add(Observer* o)
{
	// step-6 �J�X�^���������A���P�[�^�[���g���ĐV�����m�[�h���m�ۂ���B

	newNode->value = o;
	if (m_topNode == nullptr) {
		// ���X�g����
		m_topNode = newNode;
		m_tailNode = m_topNode;
	}
	else {
		// �󂶂�Ȃ���΁A�I�[�m�[�h��next�ɂȂ���B
		m_tailNode->nextNode = newNode;
		m_tailNode = newNode;
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
				prevNode->nextNode = nullptr;
			}
			else {
				// �Ԃ̃m�[�h�B
				prevNode->nextNode = p->nextNode;
			}
			// �m�[�h���폜�B
			// step-7 �J�X�^���������A���P�[�^�[�ɐV�����m�[�h��ԋp����B
			
			break;
		}
		prevNode = p;
		p = p->nextNode;
	}
}
ObserverList::Node* ObserverList::AllocNode()
{
	// step-4 �V�����m�[�h���m�ۂ��鏈���������B
	
}
/// <summary>
/// �m�[�h���J���B
/// </summary>
/// <param name="n">�J������m�[�h</param>
void ObserverList::FreeNode(Node* n)
{
	// step-5 �m�[�h��������鏈���������B

}
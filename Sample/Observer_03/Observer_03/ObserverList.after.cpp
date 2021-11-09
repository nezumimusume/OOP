#include "stdafx.h"
#include "ObserverList.h"

ObserverList::ObserverList()
{
	// step-3 �J�X�^���A���P�[�^�[�p�̃����o������������B
	// ���g�p�m�[�h�̃|�C���^�̔z�������������B
	// �ŏ��͑S�Ė��g�p�B
	for (int i = 0; i < MAX_NODE; i++) {
		m_unuserNodeArray[i] = &m_nodeArray[i];
	}
	// ���݂̖��g�p�m�[�h�̐��͍ő吔�B
	m_numUnuseNode = MAX_NODE;
}
void ObserverList::Add(Observer* o)
{
	// step-6 �J�X�^���������A���P�[�^�[���g���ĐV�����m�[�h���m�ۂ���B
	Node* newNode = AllocNode();

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
			FreeNode(p);
			break;
		}
		prevNode = p;
		p = p->nextNode;
	}
}
ObserverList::Node* ObserverList::AllocNode()
{
	// step-4 �V�����m�[�h���m�ۂ��鏈���������B
	if (m_numUnuseNode == 0) {
		// ���g�p�m�[�h���Ȃ��B
		return nullptr;
	}
	// ���g�p�m�[�h����V�����m�[�h�����炤�B
	Node* allocNode = m_unuserNodeArray[m_numUnuseNode-1];
	allocNode->nextNode = nullptr;
	allocNode->value = nullptr;

	// ���g�p�m�[�h���P���炷
	m_numUnuseNode--;
	return allocNode;
}
/// <summary>
/// �m�[�h���J���B
/// </summary>
/// <param name="n">�J������m�[�h</param>
void ObserverList::FreeNode(Node* n)
{
	// step-5 �m�[�h��������鏈���������B
	// �m�[�h�𖢎g�p���X�g�ɕԋp����B
	m_unuserNodeArray[m_numUnuseNode] = n;
	// ���g�p�m�[�h�̐����P���₷�B
	m_numUnuseNode++;
}
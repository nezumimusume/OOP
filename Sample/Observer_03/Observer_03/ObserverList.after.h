#pragma once

class Observer;

class ObserverList {
public:
	/// <summary>
	/// �m�[�h
	/// </summary>
	struct Node {
		Observer* value = nullptr;		// ���̃m�[�h���L�����Ă���I�u�U�[�o�[
		Node* nextNode = nullptr;		// ���̃m�[�h�B
	};
private:
	static const int MAX_NODE = 1024;		// �ő�́[�h
	Node* m_topNode = nullptr;					// �擪�m�[�h
	Node* m_tailNode = nullptr;					//	�I�[�m�[�h�B

	// step-1 �J�X�^���A���P�[�^�[�p�̃����o�ϐ���ǉ��B
	Node m_nodeArray[MAX_NODE];			// �m�[�h�̔z��
	Node* m_unuserNodeArray[MAX_NODE];	// ���g�p�m�[�h�̔z��
	int m_numUnuseNode = 0;						// ���g�p�m�[�h�̐��B
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	ObserverList();
	/// <summary>
	/// �I�u�U�[�o�[�����X�g�ɒǉ��B
	/// </summary>
	/// <param name="o"></param>
	void Add(Observer* o);
	/// <summary>
	/// �I�u�U�[�o�[��j��
	/// </summary>
	/// <param name="o"></param>
	void Remove(Observer* o);
	/// <summary>
	/// �擪�m�[�h���擾�B
	/// </summary>
	/// <returns></returns>
	Node* GetTopNode()
	{
		return m_topNode;
	}
private:
	// step-2 �J�X�^���������A���P�[�^�p�̃������m�ۊ֐��ƊJ���֐����`����
	// �V�����m�[�h���m�ہB
	Node* AllocNode();
	// �m�[�h���J���B
	void FreeNode(Node* n);

};
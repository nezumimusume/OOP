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
	

};
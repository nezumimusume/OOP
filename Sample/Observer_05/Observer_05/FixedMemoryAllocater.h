#pragma once

template<class TObj, int MAX_SIZE>
class TFixedMemoryAllocator {
public:
	TFixedMemoryAllocator()
	{
		for (int i = 0; i < MAX_SIZE; i++) {
			m_unuseObjArray[i] = &m_buffer[i];
		}
		// ���݂̖��g�p�m�[�h�̐��͍ő吔�B
		m_numUnuseObj = MAX_SIZE;
	}
	TObj* Alloc()
	{
		if (m_numUnuseObj == 0) {
			// ���g�p�m�[�h���Ȃ��B
			return nullptr;
		}
		// ���g�p�m�[�h����V�����m�[�h�����炤�B
		TObj* allocNode = m_unuseObjArray[m_numUnuseObj - 1];
		allocNode->nextNode = nullptr;
		allocNode->value = nullptr;

		// ���g�p�m�[�h���P���炷
		m_numUnuseObj--;
		return allocNode;
	}
	void Free(TObj* obj)
	{
		// step-5 �m�[�h��������鏈���������B
		// �m�[�h�𖢎g�p���X�g�ɕԋp����B
		m_unuseObjArray[m_numUnuseObj] = obj;
		// ���g�p�m�[�h�̐����P���₷�B
		m_numUnuseObj++;
	}
private:
	TObj m_buffer[MAX_SIZE];
	TObj* m_unuseObjArray[MAX_SIZE];
	int m_numUnuseObj = 0;
};
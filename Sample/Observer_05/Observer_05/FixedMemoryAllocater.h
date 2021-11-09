#pragma once

template<class TObj, int MAX_SIZE>
class TFixedMemoryAllocator {
public:
	TFixedMemoryAllocator()
	{
		for (int i = 0; i < MAX_SIZE; i++) {
			m_unuseObjArray[i] = &m_buffer[i];
		}
		// 現在の未使用ノードの数は最大数。
		m_numUnuseObj = MAX_SIZE;
	}
	TObj* Alloc()
	{
		if (m_numUnuseObj == 0) {
			// 未使用ノードがない。
			return nullptr;
		}
		// 未使用ノードから新しいノードをもらう。
		TObj* allocNode = m_unuseObjArray[m_numUnuseObj - 1];
		allocNode->nextNode = nullptr;
		allocNode->value = nullptr;

		// 未使用ノードを１つ減らす
		m_numUnuseObj--;
		return allocNode;
	}
	void Free(TObj* obj)
	{
		// step-5 ノードを解放する処理を実装。
		// ノードを未使用リストに返却する。
		m_unuseObjArray[m_numUnuseObj] = obj;
		// 未使用ノードの数を１つ増やす。
		m_numUnuseObj++;
	}
private:
	TObj m_buffer[MAX_SIZE];
	TObj* m_unuseObjArray[MAX_SIZE];
	int m_numUnuseObj = 0;
};
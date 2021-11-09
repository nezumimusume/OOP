#include "stdafx.h"
#include "ObserverList.h"

ObserverList::ObserverList()
{
	// step-3 カスタムアロケーター用のメンバを初期化する。
	// 未使用ノードのポインタの配列を初期化する。
	// 最初は全て未使用。
	for (int i = 0; i < MAX_NODE; i++) {
		m_unuserNodeArray[i] = &m_nodeArray[i];
	}
	// 現在の未使用ノードの数は最大数。
	m_numUnuseNode = MAX_NODE;
}
void ObserverList::Add(Observer* o)
{
	// step-6 カスタムメモリアロケーターを使って新しいノードを確保する。
	Node* newNode = AllocNode();

	newNode->value = o;
	if (m_topNode == nullptr) {
		// リストが空
		m_topNode = newNode;
		m_tailNode = m_topNode;
	}
	else {
		// 空じゃなければ、終端ノードのnextにつなげる。
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
			// 見つけた。
			if (p == m_topNode) {
				// 先頭のノード
				if (m_topNode == m_tailNode) {
					// 先頭と終端が同じということは要素数１
					m_topNode = nullptr;
					m_tailNode = nullptr;
				}
				else {
					// 複数の要素が記憶されている。
					m_topNode = p->nextNode;
				}
			}
			else if (p == m_tailNode) {
				// 終端ノード。
				m_tailNode = prevNode;
				prevNode->nextNode = nullptr;
			}
			else {
				// 間のノード。
				prevNode->nextNode = p->nextNode;
			}
			// ノードを削除。
			// step-7 カスタムメモリアロケーターに新しいノードを返却する。
			FreeNode(p);
			break;
		}
		prevNode = p;
		p = p->nextNode;
	}
}
ObserverList::Node* ObserverList::AllocNode()
{
	// step-4 新しいノードを確保する処理を実装。
	if (m_numUnuseNode == 0) {
		// 未使用ノードがない。
		return nullptr;
	}
	// 未使用ノードから新しいノードをもらう。
	Node* allocNode = m_unuserNodeArray[m_numUnuseNode-1];
	allocNode->nextNode = nullptr;
	allocNode->value = nullptr;

	// 未使用ノードを１つ減らす
	m_numUnuseNode--;
	return allocNode;
}
/// <summary>
/// ノードを開放。
/// </summary>
/// <param name="n">開放するノード</param>
void ObserverList::FreeNode(Node* n)
{
	// step-5 ノードを解放する処理を実装。
	// ノードを未使用リストに返却する。
	m_unuserNodeArray[m_numUnuseNode] = n;
	// 未使用ノードの数を１つ増やす。
	m_numUnuseNode++;
}
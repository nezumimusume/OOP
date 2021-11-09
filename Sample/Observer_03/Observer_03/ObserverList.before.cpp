#include "stdafx.h"
#include "ObserverList.h"

ObserverList::ObserverList()
{
}
void ObserverList::Add(Observer* o)
{
	// ポイントー１ デフォルトメモリアロケーターで新しいノードを確保している。
	Node* newNode = new Node;

	newNode->value = o;
	if (m_topNode == nullptr) {
		// リストが空
		m_topNode = newNode;
		m_tailNode = m_topNode;
	}
	else {
		// 空じゃなければ、終端ノードのnextにつなげる。
		m_tailNode->nextNode = newNode;
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
			}
			else {
				// 間のノード。
				prevNode->nextNode = p->nextNode;
			}
			// ポイント-2 デフォルトのカスタムメモリアロケーターにメモリを返却する。
			delete p;
			
			break;
		}
		prevNode = p;
		p = p->nextNode;
	}
}

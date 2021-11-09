#pragma once

class Observer;

class ObserverList {
public:
	/// <summary>
	/// ノード
	/// </summary>
	struct Node {
		Observer* value = nullptr;		// このノードが記憶しているオブザーバー
		Node* nextNode = nullptr;		// 次のノード。
	};
private:
	static const int MAX_NODE = 1024;		// 最大のード
	Node* m_topNode = nullptr;					// 先頭ノード
	Node* m_tailNode = nullptr;					//	終端ノード。

	// step-1 カスタムアロケーター用のメンバ変数を追加。
	Node m_nodeArray[MAX_NODE];			// ノードの配列
	Node* m_unuserNodeArray[MAX_NODE];	// 未使用ノードの配列
	int m_numUnuseNode = 0;						// 未使用ノードの数。
public:
	/// <summary>
	/// コンストラクタ。
	/// </summary>
	ObserverList();
	/// <summary>
	/// オブザーバーをリストに追加。
	/// </summary>
	/// <param name="o"></param>
	void Add(Observer* o);
	/// <summary>
	/// オブザーバーを破棄
	/// </summary>
	/// <param name="o"></param>
	void Remove(Observer* o);
	/// <summary>
	/// 先頭ノードを取得。
	/// </summary>
	/// <returns></returns>
	Node* GetTopNode()
	{
		return m_topNode;
	}
private:
	// step-2 カスタムメモリアロケータ用のメモリ確保関数と開放関数を定義する
	// 新しいノードを確保。
	Node* AllocNode();
	// ノードを開放。
	void FreeNode(Node* n);

};
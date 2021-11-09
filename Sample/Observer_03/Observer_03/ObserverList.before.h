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
	

};
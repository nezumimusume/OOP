#pragma once

#include <algorithm>
#include "Observer.h"
#include "ObserverList.h"

/// <summary>
/// 監視対象役のクラス。
/// </summary>
class Subject
{
public:
	/// <summary>
	/// オブザーバーを追加
	/// </summary>
	/// <param name="o">オブザーバー</param>
	void AddObserver(Observer* o)
	{
		m_observerList.Add(o);
	}
	/// <summary>
	/// オブザーバーを削除
	/// </summary>
	/// <param name="o">オブザーバー</param>
	void RemoveObserver(Observer* o)
	{
		m_observerList.Remove(o);
	}
	/// <summary>
	/// オブザーバーにイベントを通知する。
	/// </summary>
	/// <param name="event">イベント</param>
	/// <param name="arg_0">引数</param>
	void Notify(int event, int arg_0)
	{
		ObserverList::Node* node = m_observerList.GetTopNode();
		while (node != nullptr) {
			node->value->OnNotify(this, event, arg_0);
			node = node->nextNode;
		}
	}
private:
	ObserverList m_observerList;	// オブザーバーのリスト。
	
};


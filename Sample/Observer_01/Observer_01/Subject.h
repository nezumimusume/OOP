#pragma once

#include <algorithm>
#include "Observer.h"

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
		//　すでに登録されているオブザーバーかもしれないので、
		//　まずはそれを調査せする。
		auto itFind = std::find(m_observerList.begin(),m_observerList.end(), o );
		if (itFind == m_observerList.end()) {
			// イテレーターの終端まで行ったので未登録。
			// 追加する。
			m_observerList.emplace_back(o);
		}
	}
	/// <summary>
	/// オブザーバーを削除
	/// </summary>
	/// <param name="o">オブザーバー</param>
	void RemoveObserver(Observer* o)
	{
		//　登録されているオブザーバーか調べる。
		auto itFind = std::find(m_observerList.begin(), m_observerList.end(), o);
		if (itFind != m_observerList.end()) {
			// 登録されているので削除する。
			m_observerList.erase(itFind);
		}
	}
	/// <summary>
	/// オブザーバーにイベントを通知する。
	/// </summary>
	/// <param name="event">イベント</param>
	/// <param name="arg_0">引数</param>
	void Notify(int event, int arg_0)
	{
		for (auto& o : m_observerList) {
			o->OnNotify( this, event, arg_0 );
		}
	}
private:
	std::list< Observer* > m_observerList;
};


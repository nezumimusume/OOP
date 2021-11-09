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
		if (m_observerHead == nullptr) {
			m_observerHead = o;
			m_observerHead->SetNext(nullptr);
		}
		//　すでに登録されているか調べる。
		bool isFind = false;
		Observer* oEnd = nullptr;
		Observer* oTmp = m_observerHead;
		while (oTmp != nullptr) {
			if (oTmp == o) {
				// すでに追加されている。
				isFind = true;
				break;
			}
			oEnd = oTmp;
			oTmp = oTmp->GetNext();
		}
		if (isFind == false) {
			// リストの末尾にオブザーバーを連結する。
			oEnd->SetNext(o);
			o->SetNext(nullptr);
		}
	}
	/// <summary>
	/// オブザーバーを削除
	/// </summary>
	/// <param name="o">オブザーバー</param>
	void RemoveObserver(Observer* o)
	{
		//　登録されか調べる
		Observer* oPrev = nullptr;
		Observer* oTmp = m_observerHead;
		while (oTmp != nullptr) {
			if (oTmp == o) {
				// 登録されていた。
				if (oPrev == nullptr) {
					// 先頭のオブザーバー
					// オブザーバーの先頭を変更する。
					m_observerHead = o->GetNext();
				}
				else {
					// 間のオブザーバー。
					// リンクを入れ替える。
					oPrev->SetNext(o->GetNext());
				}
				break;
			}
			oPrev = oTmp;
			oTmp = oTmp->GetNext();
		}
	}
	/// <summary>
	/// オブザーバーにイベントを通知する。
	/// </summary>
	/// <param name="event">イベント</param>
	/// <param name="arg_0">引数</param>
	void Notify(int event, int arg_0)
	{
		Observer* o = m_observerHead;
		while (o != nullptr) {
			o->OnNotify(this, event, arg_0);
			o = o->GetNext();
		}
	}
private:
	Observer* m_observerHead = nullptr;
	
};


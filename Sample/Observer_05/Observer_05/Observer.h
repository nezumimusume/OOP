#pragma once

class Subject;

class Observer
{
public:
	/// <summary>
	/// 監視しているオブジェクトからの通知メッセージを受け取る関数。
	/// </summary>
	/// <param name="pSubject">メッセージを送ってきたサブジェクト</param>
	/// <param name="event">イベント</param>
	/// <param name="arg_0"></param>
	virtual void OnNotify( Subject* pSubject, int event, int arg_0 ) = 0;
	/// <summary>
	/// 次のオブザーバーを取得。
	/// </summary>
	/// <returns></returns>
	Observer* GetNext() const
	{
		return m_next;
	}
	/// <summary>
	/// 次のオブザーバーを設定。
	/// </summary>
	/// <param name="next"></param>
	void SetNext(Observer* next)
	{
		m_next = next;
	}
private:
	Observer* m_next = nullptr;	// 次のオブザーバー。
};


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
};


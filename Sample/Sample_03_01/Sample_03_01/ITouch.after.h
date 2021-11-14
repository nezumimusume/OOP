#pragma once

// step-1 タッチ状況を取得するためのインターフェースクラスを実装する。
class ITouch
{
public:
	// タッチされた座標を取得。
	// x : x座標
	// y : y座標
	virtual void GetTouchPosition(float& x, float& y) const = 0;
	// 画面がタッチされているか判定。
	// trueが返ってくるとタッチされている。
	virtual bool IsPressTouch() const = 0;
};


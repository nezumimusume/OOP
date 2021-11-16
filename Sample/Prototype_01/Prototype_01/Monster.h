#pragma once

// モンスターの基底クラス。
class Monster
{
public:
	// クローンを生成。
	virtual Monster* Clone() = 0;
	// 座標を設定。
	void SetPosition(float x, float y)
	{
		m_posX = x;
		m_posY = y;
	}
	// X座標を取得。
	float GetPosX() const
	{
		return m_posX;
	}
	// Y座標を取得。
	float GetPosY() const
	{
		return m_posY;
	}
private:
	float m_posX;	// x座標。
	float m_posY;	// y座標。
};


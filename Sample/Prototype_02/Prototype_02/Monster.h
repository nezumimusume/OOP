#pragma once

// �����X�^�[�̊��N���X�B
class Monster
{
public:
	// �N���[���𐶐��B
	virtual Monster* Clone() = 0;
	// ���W��ݒ�B
	void SetPosition(float x, float y)
	{
		m_posX = x;
		m_posY = y;
	}
	// X���W���擾�B
	float GetPosX() const
	{
		return m_posX;
	}
	// Y���W���擾�B
	float GetPosY() const
	{
		return m_posY;
	}
private:
	float m_posX;	// x���W�B
	float m_posY;	// y���W�B
};


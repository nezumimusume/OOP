#pragma once

#include "InGame.h"
#include "Monster.h"

// �����X�^�[�X�|�[�i�[
template<class T> 
class MonsterSpawner
{
public:
	// �R���X�g���N�^�B
	MonsterSpawner(
		InGame& inGame,  
		int spawnTime):
		m_prototypeMonster(monster),
		m_spawnTime(spawnTime),
		m_inGame(inGame)
	{}
	// ���W��ݒ�B
	void SetPosition( float posX, float posY )
	{
		m_posX = posX;
		m_posY = posY;
	}
	// �X�V
	void Update()
	{
		m_timer++;
		if (m_spawnTime <= m_timer) {
			// �����X�^�[���X�|�[������B
			Monster* monster = m_prototypeMonster.Clone();
			// �X�|�[�i�[�̍��W��ݒ肷��B
			monster->SetPosition(m_posX, m_posY);
			// �X�|�[�����������X�^�[���C���Q�[���ɓo�^����B
			m_inGame.AddMonster(monster);
			m_timer = 0;
		}
	}
private:
	InGame& m_inGame;				// �C���Q�[��
	T& m_prototypeMonster;			// �ЂȌ`�ƂȂ郂���X�^�[�B
	const int m_spawnTime;			// �X�|�[������܂ł̃^�C���B
	int m_timer = 0;				// �^�C�}�[
	float m_posX = 0.0f;			// X���W�B
	float m_posY = 0.0f;			// Y���W�B
};


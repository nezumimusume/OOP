#pragma once

#include "Monster.h"
class InGame;

// �����X�^�[�X�|�[�i�[
class MonsterSpawner
{
public:
	// �R���X�g���N�^�B
	MonsterSpawner(
		InGame& inGame, 
		Monster& monster, 
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
	void Update();
private:
	InGame& m_inGame;				// �C���Q�[��
	Monster& m_prototypeMonster;	// �ЂȌ`�ƂȂ郂���X�^�[�B
	const int m_spawnTime;			// �X�|�[������܂ł̃^�C���B
	int m_timer = 0;				// �^�C�}�[
	float m_posX = 0.0f;			// X���W�B
	float m_posY = 0.0f;			// Y���W�B
};


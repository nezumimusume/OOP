#pragma once

#include "MonsterSpawner.h"
#include "Slime.h"
#include "Demon.h"
#include "Gobrin.h"
#include <list>

class InGame
{
public:
	// �R���X�g���N�^�B
	InGame();
	// �X�V����
	void Update();
	// �����X�^�[��ǉ��B
	void AddMonster(Monster* monster)
	{
		m_monsterList.push_back(monster);
	}
private:
	MonsterSpawner m_gobrinSpawner;		// �S�u�����̃X�|�[�i�[�B
	MonsterSpawner m_slimeSpawner;		// �X���C���̃X�|�[�i�[�B
	MonsterSpawner m_demonSpawner;		// �f�[�����̃X�|�[�i�[�B
	Slime m_prototypeSlime;				// �X���C���̂ЂȌ`�I�u�W�F�N�g�B
	Demon m_prototypeDemon;				// �f�[�����̂ЂȌ`�I�u�W�F�N�g�B
	Gobrin m_prototypeGobrin;			// �S�u�����̂ЂȌ`�I�u�W�F�N�g�B
	std::list<Monster*> m_monsterList;	// �����X�^�[�̃��X�g�B
};


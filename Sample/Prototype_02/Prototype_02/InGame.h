#pragma once

#include "MonsterSpawner.h"
#include "Slime.h"
#include "Demon.h"
#include "Gobrin.h"
#include <list>

class InGame
{
public:
	// コンストラクタ。
	InGame();
	// 更新処理
	void Update();
	// モンスターを追加。
	void AddMonster(Monster* monster)
	{
		m_monsterList.push_back(monster);
	}
private:
	MonsterSpawner m_gobrinSpawner;		// ゴブリンのスポーナー。
	MonsterSpawner m_slimeSpawner;		// スライムのスポーナー。
	MonsterSpawner m_demonSpawner;		// デーモンのスポーナー。
	Slime m_prototypeSlime;				// スライムのひな形オブジェクト。
	Demon m_prototypeDemon;				// デーモンのひな形オブジェクト。
	Gobrin m_prototypeGobrin;			// ゴブリンのひな形オブジェクト。
	std::list<Monster*> m_monsterList;	// モンスターのリスト。
};


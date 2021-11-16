#include "MonsterSpawner.h"
#include "InGame.h"

void MonsterSpawner::Update()
{
	m_timer++;
	if (m_spawnTime <= m_timer) {
		// モンスターをスポーンする。
		Monster* monster = m_prototypeMonster.Clone();
		// スポーナーの座標を設定する。
		monster->SetPosition(m_posX, m_posY);
		// スポーンしたモンスターをインゲームに登録する。
		m_inGame.AddMonster(monster);
		m_timer = 0;
	}
}
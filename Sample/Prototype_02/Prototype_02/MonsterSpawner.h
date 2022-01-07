#pragma once

#include "InGame.h"
#include "Monster.h"

// モンスタースポーナー
template<class T> 
class MonsterSpawner
{
public:
	// コンストラクタ。
	MonsterSpawner(
		InGame& inGame,  
		int spawnTime):
		m_prototypeMonster(monster),
		m_spawnTime(spawnTime),
		m_inGame(inGame)
	{}
	// 座標を設定。
	void SetPosition( float posX, float posY )
	{
		m_posX = posX;
		m_posY = posY;
	}
	// 更新
	void Update()
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
private:
	InGame& m_inGame;				// インゲーム
	T& m_prototypeMonster;			// ひな形となるモンスター。
	const int m_spawnTime;			// スポーンするまでのタイム。
	int m_timer = 0;				// タイマー
	float m_posX = 0.0f;			// X座標。
	float m_posY = 0.0f;			// Y座標。
};


#pragma once

#include "Monster.h"
class InGame;

// モンスタースポーナー
class MonsterSpawner
{
public:
	// コンストラクタ。
	MonsterSpawner(
		InGame& inGame, 
		Monster& monster, 
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
	void Update();
private:
	InGame& m_inGame;				// インゲーム
	Monster& m_prototypeMonster;	// ひな形となるモンスター。
	const int m_spawnTime;			// スポーンするまでのタイム。
	int m_timer = 0;				// タイマー
	float m_posX = 0.0f;			// X座標。
	float m_posY = 0.0f;			// Y座標。
};


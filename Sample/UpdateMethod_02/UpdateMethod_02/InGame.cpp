#include "stdafx.h"
#include "InGame.h"
#include "GameWorld.h"
#include "Skeleton.h"

// step-2 インゲームの処理を制御するクラス定義を実装する。
void InGame::Update(const UpdateArg& arg)
{
	m_spawnTimer += arg.frameDuration;
	if (m_spawnTimer > 5.0f) {
		// 5秒経過でスケルトンを生成する。
		m_spawnSkeletonCount++;
		m_spawnTimer = 0.0f;
		// スケルトンゲームオブジェクトを生成する。
		arg.world->NewGameObject<Skeleton>(m_spawnSkeletonCount);
	}
}
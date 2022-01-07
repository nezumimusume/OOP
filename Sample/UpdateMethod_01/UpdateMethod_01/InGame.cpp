#include "stdafx.h"
#include "InGame.h"
#include "GameWorld.h"
#include "Skeleton.h"

void InGame::Update(const UpdateArg& arg)
{
	m_spawnTimer += arg.frameDuration;
	if (m_spawnTimer > 5.0f) {
		// 5秒経過でエネミーをスポーンする。
		m_spawnSkeletonCount++;
		m_spawnTimer = 0.0f;
		arg.world->NewGameObject<Skeleton>(m_spawnSkeletonCount);
	}
}
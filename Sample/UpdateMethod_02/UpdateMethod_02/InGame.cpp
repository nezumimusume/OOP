#include "stdafx.h"
#include "InGame.h"
#include "GameWorld.h"
#include "Skeleton.h"

// step-2 �C���Q�[���̏����𐧌䂷��N���X��`����������B
void InGame::Update(const UpdateArg& arg)
{
	m_spawnTimer += arg.frameDuration;
	if (m_spawnTimer > 5.0f) {
		// 5�b�o�߂ŃX�P���g���𐶐�����B
		m_spawnSkeletonCount++;
		m_spawnTimer = 0.0f;
		// �X�P���g���Q�[���I�u�W�F�N�g�𐶐�����B
		arg.world->NewGameObject<Skeleton>(m_spawnSkeletonCount);
	}
}
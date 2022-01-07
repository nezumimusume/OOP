#include "stdafx.h"
#include "Skeleton.h"
#include "GameWorld.h"


Skeleton::Skeleton(int no)
{
	m_no = no;
	printf("�X�P���g��%02d�����ꂽ�B\n", no);
}
void Skeleton::Update(const UpdateArg& arg)
{
	m_shoutTimer += arg.frameDuration;
	m_deathTimer += arg.frameDuration;
	if (m_shoutTimer > 2.0f) {
		printf("�X�P���g��%02d�����K���������B\n", m_no);
		m_shoutTimer = 0.0f;
	}
	if (m_deathTimer > 10.0f) {
		printf("�X�P���g��%02d�����ł����B\n", m_no);
		arg.world->DeleteGameObject(this);
	}
	
}
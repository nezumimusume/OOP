#include "stdafx.h"
#include "Skeleton.h"
#include "GameWorld.h"


Skeleton::Skeleton(int no)
{
	m_no = no;
	printf("スケルトン%02dが現れた。\n", no);
}
void Skeleton::Update(const UpdateArg& arg)
{
	m_shoutTimer += arg.frameDuration;
	m_deathTimer += arg.frameDuration;
	if (m_shoutTimer > 2.0f) {
		printf("スケルトン%02dが咆哮をあげた。\n", m_no);
		m_shoutTimer = 0.0f;
	}
	if (m_deathTimer > 10.0f) {
		printf("スケルトン%02dが消滅した。\n", m_no);
		arg.world->DeleteGameObject(this);
	}
	
}
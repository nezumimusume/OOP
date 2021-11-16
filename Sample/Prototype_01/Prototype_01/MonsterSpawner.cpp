#include "MonsterSpawner.h"
#include "InGame.h"

void MonsterSpawner::Update()
{
	m_timer++;
	if (m_spawnTime <= m_timer) {
		// �����X�^�[���X�|�[������B
		Monster* monster = m_prototypeMonster.Clone();
		// �X�|�[�i�[�̍��W��ݒ肷��B
		monster->SetPosition(m_posX, m_posY);
		// �X�|�[�����������X�^�[���C���Q�[���ɓo�^����B
		m_inGame.AddMonster(monster);
		m_timer = 0;
	}
}
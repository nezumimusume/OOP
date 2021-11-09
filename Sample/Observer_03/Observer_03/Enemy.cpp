#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(Player& player) :
	m_player(player)
{
	// �v���C���[�̊Ď��҂Ƃ��ēo�^�B
	m_player.AddObserver(this);

}

Enemy::~Enemy()
{
	m_player.RemoveObserver(this);
}

void Enemy::OnNotify(Subject* pSubject, int event, int arg_0)
{

}
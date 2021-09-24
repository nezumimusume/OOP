#include "stdafx.h"
#include "Enemy.h"
#include <random>

Enemy::Enemy() 
{
	// ���f���`�揈�����������B
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/enemy/enemy.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
}
/// <summary>
/// ���t���[���Ă΂��X�V�����B
/// </summary>
void Enemy::Update()
{
	// step-4 �ړ�������EnemyRandomMove�ɈϏ�����B

	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}
/// <summary>
/// ���t���[���Ă΂��`�揈���B
/// </summary>
/// <param name="rc"></param>
void Enemy::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
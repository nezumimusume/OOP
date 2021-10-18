#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	ModelInitData modelInitData;
	modelInitData.m_tkmFilePath = "Assets/modelData/unityChan.tkm";
	modelInitData.m_fxFilePath = "Assets/shader/model.fx";
	m_model.Init(modelInitData);
}

void Player::Update()
{
	m_position.x += g_pad[0]->GetLStickXF() * -2.0f;
	m_position.z += g_pad[0]->GetLStickYF() * -2.0f;
	m_model.UpdateWorldMatrix(m_position, g_quatIdentity, g_vec3One);
}

void Player::Draw(RenderContext& rc)
{
	m_model.Draw(rc);
}
#include "InGame.h"

InGame::InGame() :
	m_gobrinSpawner(*this, m_prototypeGobrin, 6),
	m_slimeSpawner(*this, m_prototypeSlime, 12),
	m_demonSpawner(*this, m_prototypeDemon, 24)
{
	// スポーナーの座標を設定する。
	m_gobrinSpawner.SetPosition(10, 20);

}
void InGame::Update()
{
	m_gobrinSpawner.Update();
	m_slimeSpawner.Update();
}
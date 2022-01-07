#include "stdafx.h"
#include "GameWorld.h"
#include "IGameObject.h"


void GameWorld::ExecuteGameLoop()
{
	while (true) {
		IGameObject::UpdateArg updateArg;
		updateArg.world = this;
		updateArg.frameDuration = 1.0f / 60.0f;	// 60fps�Œ�

		// �o�^����Ă���I�u�W�F�N�g�̍X�V�֐����Ăяo���B
		for (auto go : m_gameObjectList) {
			go->Update(updateArg);
		}

		// �폜�t���O�������Ă���Q�[���I�u�W�F�N�g��j������B
		m_gameObjectList.remove_if([&](IGameObject* obj) {
			if (obj->IsMarkDelete()) {
				delete obj;
				return true;
			}
			return false;
		});

		// �����������G�~�����[�g�B
		Sleep(16);
	}
}
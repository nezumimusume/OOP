#include "stdafx.h"
#include "GameWorld.h"
#include "IGameObject.h"


void GameWorld::ExecuteGameLoop()
{
	while (true) {
		IGameObject::UpdateArg updateArg;
		updateArg.world = this;
		updateArg.frameDuration = 1.0f / 60.0f;	// 60fps固定

		// 登録されているオブジェクトの更新関数を呼び出す。
		for (auto go : m_gameObjectList) {
			go->Update(updateArg);
		}

		// 削除フラグが立っているゲームオブジェクトを破棄する。
		m_gameObjectList.remove_if([&](IGameObject* obj) {
			if (obj->IsMarkDelete()) {
				delete obj;
				return true;
			}
			return false;
		});

		// 垂直同期をエミュレート。
		Sleep(16);
	}
}
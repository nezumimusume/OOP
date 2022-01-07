#pragma once

// step-1 �Q�[�����[���h�N���X�̐錾���쐬����B
#include "IGameObject.h"

/// <summary>
/// �Q�[�����[���h
/// </summary>
class GameWorld
{
public:
	/// <summary>
	/// �Q�[�����[�v�����s
	/// </summary>
	void ExecuteGameLoop();
	/// <summary>
	/// �V�����Q�[���I�u�W�F�N�g��ǉ��B
	/// </summary>
	/// <typeparam name="T">�쐬����Q�[���I�u�W�F�N�g�̌^</typeparam>
	/// <typeparam name="...CtorArgs">�R���X�g���N�^�ɓn���ϒ�����</typeparam>
	/// <param name="...ctorArgs">�R���X�g���N�^�ɓn���ϒ�����</param>
	/// <returns></returns>
	template<class T, class... CtorArgs> 
	T* NewGameObject(CtorArgs... ctorArgs)
	{
		T* newObj = new T(ctorArgs...);
		m_gameObjectList.push_back(newObj);
		return newObj;
	}
	/// <summary>
	/// �Q�[���I�u�W�F�N�g��j���B
	/// </summary>	
	/// <param name="go">�쐬����Q�[���I�u�W�F�N�g</param>
	void DeleteGameObject(IGameObject* go)
	{
		// DeleteGameObject��Update�֐����Ăяo���Ă���Œ��ɌĂ΂��\�������ɍ����B
		// ���̂��߁A�����Ń��X�g����̍폜�A�������̉�����s���ƕs���������A�N�Z�X���N����\������������B
		// ���̂��߁A�����ł̓��X�g����폜�������ɁA�폜�t���O�݂̂𗧂ĂāA�x��č폜���s���B
		go->SetMarkDelete();
	}
private:
	std::list< IGameObject*> m_gameObjectList;			// �Q�[���I�u�W�F�N�g�̃��X�g�B
};


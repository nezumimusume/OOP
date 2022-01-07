#pragma once


class GameWorld;

/// <summary>
/// �Q�[���I�u�W�F�N�g�̊��N���X�B
/// </summary>
class IGameObject
{
public:
	/// <summary>
	/// �X�V�֐��ɓn�������B
	/// </summary>
	struct UpdateArg {
		GameWorld* world;		// �Q�[�����[���h
		float frameDuration;	// 1�t���[���̊Ԋu(�P��:�b)�B
	};
	/// <summary>
	/// ���t���[���Ă΂��X�V�֐��B
	/// </summary>
	virtual void Update(const UpdateArg& arg) = 0;
	/// <summary>
	/// �폜�̈��t����B
	/// </summary>
	void SetMarkDelete()
	{
		m_isDelete = true;
	}
	/// <summary>
	/// �폜�̈󂪂��Ă���H
	/// </summary>
	/// <returns></returns>
	bool IsMarkDelete() const
	{
		return m_isDelete;
	}
private:
	bool m_isDelete = false;	// �폜�t���O�B
};


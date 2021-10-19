#pragma once

#include "Observer.h"

class Player;

/// <summary>
/// ���уN���X
/// </summary>
class Achievement : public Observer
{
public:
	/// <summary>
	/// �R���X�g���N�^�B
	/// </summary>
	Achievement(Player& player);
	
	/// <summary>
	/// �f�X�g���N�^�B
	/// </summary>
	~Achievement();
	/// <summary>
	/// �Ď����Ă���T�u�W�F�N�g�ŃC�x���g�����������Ƃ��ɌĂ΂�鏈��
	/// </summary>
	/// <param name="pSubject"></param>
	/// <param name="event"></param>
	/// <param name="arg_0"></param>
	void OnNotify(Subject* pSubject, int event, int arg_0) override;
private:
	/// <summary>
	/// ���т̎��
	/// </summary>
	enum class EnAchivement {
		FIRST_JUMP,		// ���߂ẴW�����v�B
		FIVE_JUMP,		// �W�����v���T�񂵂��B
		NUM,			// ���т̐��B
	};
	Player* m_player = nullptr;	// �v���C���[�B
	int m_jumpCount = 0;
	bool m_isCompleted[(int)EnAchivement::NUM] = { false };	// ���т̒B���t���O�B
};


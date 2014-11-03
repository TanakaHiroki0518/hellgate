/*
�Q�[���̃��C��
 */
#ifndef __GAME_MAIN__H__
#define __GAME_MAIN__H__

#include <iostream>
#include <DxLib.h>
#include "fps\fps.h"

#define KEY_MAX 256


enum keyPress
{
	disable = 0, // �����Ă��Ȃ�
	enable, // �������u��
	keepEnable, // ���������Ă���
};

class game_main
{
// �֐�
public:
	// �R���X�g���N�^, �f�X�g���N�^
	game_main();
	virtual ~game_main();

	// �Q�[�����C��
	void GameMain();
private:
	// �L�[����
	int m_GetHitKeyStateAll();
	// �V�X�e������
	bool systemProcess();
	// �`�揈��
	void DrawProcess();
	// �Q�[������������
	void GameInit();
	// �Q�[���I��
	void GameEnd();
// �ϐ�
public:
private:
	char m_Key[KEY_MAX]; // �L�[����p
	fps fps; // fps�����p
};


#endif /*__GAME_MAIN__H__*/

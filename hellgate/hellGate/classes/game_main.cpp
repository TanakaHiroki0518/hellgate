/*
�Q�[�����C��
 */

#include "game_main.h"
#include "common\resourcesCommon.h"

// �R���X�g���N�^
game_main::game_main()
{
}

// �f�X�g���N�^
game_main::~game_main()
{
}

// �Q�[�����C��
void game_main::GameMain()
{
	// TRUE = �E�B���h�E���[�h, FALSE = �t���X�N���[��
	ChangeWindowMode(TRUE);
	
	// �𑜓x(int width, int height), �\�����x�F��(int colorNum), fps(=60)
	SetGraphMode(WINDOW_SIZE_W,WINDOW_SIZE_H,WINDOW_COLOR);

	// �E�B���h�E�\���ɗ�O or dxlib�̏������~�X
	if( ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK || DxLib_Init() == -1 )
	{
		// �G���[�Ȃ̂ŏI������
		return;
	}

	// ����ʂɐݒ�(�����)
    SetDrawScreen( DX_SCREEN_BACK );
	
	// �Q�[���̏���������
	this->GameInit();

	// ���炩�̃G���[�����m or esc�L�[���������܂Ń��[�v
	while(true)
	{
		// �G���[���o
		if(!this->systemProcess())
		{
			break;
		}

		// �Q�[������

		// �`�揈��
		this->DrawProcess();
	}

	// �I������
	this->GameEnd();
	
	return;
}

// �Q�[��������
void game_main::GameInit()
{
	// fps�̏�����
	fps.init();

	// fps�̕\����\���؂�ւ�(true = �\��, false = ��\��)
	fps.isVisibleFPS(true);

	return;
}

// �Q�[���I��
void game_main::GameEnd()
{
	// BGM, SE�̒�~
	StopMusic();
	//	�`��Ǘ����W���[���E�I��

	//	DX���C�u�����E�I��
	DxLib_End();

	return;
}

// �V�X�e������
bool game_main::systemProcess()
{
	// �v���Z�X���b�Z�[�W
	ProcessMessage();

	//	��ʂ�������
	ClearDrawScreen();

	// �L�[����
	this->m_GetHitKeyStateAll();

	// esc�L�[�ŏI��
	if(m_Key[KEY_INPUT_ESCAPE] != keyPress::disable)
	{
		// esc�L�[�������ꂽ
		return false;
	}
	
	return true;
}

// �`�揈��
void game_main::DrawProcess()
{
	//fps����
	fps.update();
	
	// ����ʂƕ\��ʂ����ւ���
	ScreenFlip();

	return;
}

// �L�[���͔���
int game_main::m_GetHitKeyStateAll()
{
	// ������Ă���L�[�̎擾
	char GetHitKeyStateAll_Key[KEY_MAX];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );

	// �L�[�̃X�e�[�^�X�i�[
	for(int i = 0; i != KEY_MAX; i++)
	{
		if(GetHitKeyStateAll_Key[i] >= keyPress::enable)
		{
			// ���������Ă���
			this->m_Key[i] = keyPress::keepEnable;
		}
		else if(GetHitKeyStateAll_Key[i] != keyPress::disable)
		{
			// �����ꂽ�u��
			this->m_Key[i] = keyPress::enable;
		}
		else
		{
			// �w�肵���L�[�͉�����Ă��Ȃ�
			this->m_Key[i] = keyPress::disable;
		}
	}

	return 0;
}


//=======================================================================================
//			���C���֐�
//			����N/��/��		�����
//			  2014/11/2			H.tanaka
//=======================================================================================
#include <Windows.h>
int WINAPI WinMain(
  HINSTANCE hInstance,      // ���݂̃C���X�^���X�̃n���h��
  HINSTANCE hPrevInstance,  // �ȑO�̃C���X�^���X�̃n���h��
  LPSTR lpCmdLine,          // �R�}���h���C��
  int nCmdShow              // �\�����
)
{
	// �Q�[�����C���֐��̌Ăяo��
	game_main main;
	main.GameMain();

	return	0;
}

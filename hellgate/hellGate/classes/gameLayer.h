/*
�ėp�V�[���N���X
 */

#ifndef __GAME_LAYER__H__
#define __GAME_LAYER__H__

#include <DxLib.h>
#include <iostream>
#include <map>

class gameLayer
{
public:
	// �R���X�g���N�^
	gameLayer();
	// �f�X�g���N�^
	virtual ~gameLayer();

	// �V�[���ɓ����Ă������Ɏ��s�����
	virtual onEnter();
	// �V�[�����o�����Ɏ��s�����
	virtual onExit();

	// �摜���i�[
	virtual addChild();
	virtual addChild(std::string tag);
private:
};


#endif /*__GAME_LAYER__H__*/

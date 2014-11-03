/*
sprite��舵���N���X
 */
#ifndef __SPRITE__H__
#define __SPRITE__H__

#include <iostream>
#include <DxLib.h>

// �X�v���C�g�̃X�e�[�^�X�\����
struct spriteStatus
{
public:
	// �摜�i�[�p
	int graphic;
	// �\����\��
	bool isVisible;	// true=�\��, false=��\��
	// ���W
	int	pos_x;		// x���W
	int	pos_y;		// y���W
	// �[�x
	int	zOrder;		// �摜�̕\���[�x(0 = ��ʍőO��, 65535 = ��ʍŐ[��)
	// �X�v���C�g�T�C�Y
	int	height;		// �摜�̍���
	int	width;		// �摜�̕�
	// �A�j���[�V�����p������
	int allnum;		// ������
	int x_num;		// ��������
	int y_num;		// �c������
	// �����x
	int	nAlpha;		// ���ߐF�w��
};

class sprite
{
public:
	// �R���X�g���N�^, �f�X�g���N�^
	sprite();
	virtual ~sprite();

	// create
	void createWithNode(const char* nodePath);
private:
	bool init();
	const char* convertGraPath(const char* path);
private:
	spriteStatus* m_spr;
};

#endif /*__SPRITE__H__*/

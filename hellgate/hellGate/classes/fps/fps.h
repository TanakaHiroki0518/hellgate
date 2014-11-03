/*
fps����
 */
#ifndef __FPS_H__
#define __FPS_H__

#include <iostream>
#include <DxLib.h>

#define FPS  60.0f //�ݒ肵��FPS
#define MM_CONVERT_TIME 1000.0f // �~���b����b�ւ̕ϊ��p

class fps
{
public:
	// �R���X�g���N�^
	fps();
	// �f�X�g���N�^
	virtual ~fps();

	// ������
	void init();
	// update
	bool update();

	// fps�̕\����\���؂�ւ�
	void isVisibleFPS(bool isVisible) { this->m_isVisible = isVisible; };
private:
	void draw();
	void wait();

private:
	float m_StartTime; //����J�n����
	float m_Count; //�J�E���^
	float m_Fps; //fps
	bool m_isVisible; // fps�̕\����\��
};

#endif /*__FPS_H__*/

/*
fps����
 */
#include <math.h>
#include "fps.h"
#include "..\common\resourcesCommon.h"

//=======================================================================================
//			fps�����p�֐�
//			����N����			�����
//			2014/11/2			H.tanaka
//=======================================================================================

// �R���X�g���N�^
fps::fps()
: m_StartTime(0.f)
, m_Count(0.f)
, m_Fps(0.f)
, m_isVisible(false)
{
}

// �f�X�g���N�^
fps::~fps()
{
}

// ������
void fps::init()
{
	// �����o�ϐ��̏�����
	this->m_StartTime = 0.0f;
	this->m_Count = 0.0f;
	this->m_Fps = 0.0f;
}

bool fps::update()
{
	if( this->m_Count == 0 )
	{
		//1�t���[���ڂȂ玞�����L��
		this->m_StartTime = (float)GetNowCount();
	}
	else if( this->m_Count == FPS )
	{
		//60�t���[���ڂȂ畽�ς��v�Z����
		const float finTime = (float)GetNowCount();
		this->m_Fps = MM_CONVERT_TIME / ((finTime - this->m_StartTime) / (float)FPS);
		this->m_Count = 0;
		// ����̃X�^�[�g�ɍ���̍Ō�̎��Ԃ��i�[����
		this->m_StartTime = finTime;

		// wait
		this->wait();
	}

	// draw
	this->draw();

	this->m_Count++;

	return true;
}

void fps::draw()
{
	// fps����\���Ȃ�return
	if(!this->m_isVisible)
	{
		return;
	}

	//�t�H���g
	SetFontSize(10);
	DrawFormatString(0, 0, cWhite, L"fps: %.1f / 60", this->m_Fps);
}

void fps::wait()
{
	float tookTime = GetNowCount() - this->m_StartTime;	//������������
	float waitTime = this->m_Count * MM_CONVERT_TIME / FPS - tookTime;	//�҂ׂ�����
	if( waitTime > 0 )
	{
		Sleep((int)waitTime);	//�ҋ@
	}
}

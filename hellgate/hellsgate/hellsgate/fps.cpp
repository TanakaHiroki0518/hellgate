#pragma warning(disable:4100)

#include <DxLib.h>
#include "fps.h"


//=======================================================================================
//			fps�����p�֐�
//			����N����			�����
//			2012/12/18			H.tanaka
//=======================================================================================

// static�����o
int fps::mStartTime;      //����J�n����
int fps::mCount;          //�J�E���^
float fps::mFps;          //fps

fps::fps()
{
	init();
}

fps::~fps()
{
}

void fps::init()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0.f;
}

bool fps::Update()
{
	if( mCount == 0 )
	{ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	else if( mCount == FPS )
	{ //60�t���[���ڂȂ畽�ς��v�Z����
		int nowTime = GetNowCount();
		mFps = 1000.f / ((nowTime - mStartTime) / (float)FPS);
		mCount = 0;
		mStartTime = nowTime;
	}
	mCount++;
	return true;
}

void fps::Draw()
{
	//�t�H���g
	SetFontSize(10);
	DrawFormatString(0, 0, WHITE, L"fps %.1f", mFps);
}

void fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = ((mCount * 1000) / FPS) - tookTime;	//�҂ׂ�����
	if( waitTime > 0 )
	{
		Sleep(waitTime);	//�ҋ@
	}
}

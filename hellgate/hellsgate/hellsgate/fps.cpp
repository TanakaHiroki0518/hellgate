#pragma warning(disable:4100)

#include <DxLib.h>
#include "fps.h"


//=======================================================================================
//			fps調整用関数
//			制作年月日			制作者
//			2012/12/18			H.tanaka
//=======================================================================================

// staticメンバ
int fps::mStartTime;      //測定開始時刻
int fps::mCount;          //カウンタ
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
	{ //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	else if( mCount == FPS )
	{ //60フレーム目なら平均を計算する
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
	//フォント
	SetFontSize(10);
	DrawFormatString(0, 0, WHITE, L"fps %.1f", mFps);
}

void fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = ((mCount * 1000) / FPS) - tookTime;	//待つべき時間
	if( waitTime > 0 )
	{
		Sleep(waitTime);	//待機
	}
}

/*
fps調整
 */
#include <math.h>
#include "fps.h"
#include "..\common\resourcesCommon.h"

//=======================================================================================
//			fps調整用関数
//			制作年月日			制作者
//			2014/11/2			H.tanaka
//=======================================================================================

// コンストラクタ
fps::fps()
: m_StartTime(0.f)
, m_Count(0.f)
, m_Fps(0.f)
, m_isVisible(false)
{
}

// デストラクタ
fps::~fps()
{
}

// 初期化
void fps::init()
{
	// メンバ変数の初期化
	this->m_StartTime = 0.0f;
	this->m_Count = 0.0f;
	this->m_Fps = 0.0f;
}

bool fps::update()
{
	if( this->m_Count == 0 )
	{
		//1フレーム目なら時刻を記憶
		this->m_StartTime = (float)GetNowCount();
	}
	else if( this->m_Count == FPS )
	{
		//60フレーム目なら平均を計算する
		const float finTime = (float)GetNowCount();
		this->m_Fps = MM_CONVERT_TIME / ((finTime - this->m_StartTime) / (float)FPS);
		this->m_Count = 0;
		// 次回のスタートに今回の最後の時間を格納する
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
	// fpsが非表示ならreturn
	if(!this->m_isVisible)
	{
		return;
	}

	//フォント
	SetFontSize(10);
	DrawFormatString(0, 0, cWhite, L"fps: %.1f / 60", this->m_Fps);
}

void fps::wait()
{
	float tookTime = GetNowCount() - this->m_StartTime;	//かかった時間
	float waitTime = this->m_Count * MM_CONVERT_TIME / FPS - tookTime;	//待つべき時間
	if( waitTime > 0 )
	{
		Sleep((int)waitTime);	//待機
	}
}

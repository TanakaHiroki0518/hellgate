/*
 * FPS.cpp
 * 2015/08/23 tanaka.h
 */
#include "FPS.h"

FPS* FPS::_instance = nullptr;

FPS* FPS::getInstance()
{
	if(!_instance)
	{
		_instance = new FPS();
	}
	return _instance;
}

void FPS::deleteInstance()
{
	delete _instance;
}

bool FPS::update()
{
	bool isDrawFPS = false;
	float elapsedTime = 0.0f;

	//1フレーム目なら時刻を記憶
	if(_frameCount == 0)
	{
		_startTime = GetNowCount();
		_frameCount++;
	}
	//60フレーム目なら平均を計算する
	else if(_frameCount >= DefaultFPS)
	{
		float finishTime = GetNowCount();
		elapsedTime = (finishTime - _startTime);
		_fps = 1000.f / (elapsedTime / DefaultFPS);

		isDrawFPS = true;
	}
	// それ以外なら、countを加算
	else
	{
		_frameCount++;
	}

	// ラベル表示
	if(_fps != 0.0f)
	{
		const std::string& str = fw::getStrWithFormat("fps: %.1f", _fps);
		fw::DrawLabel(str.c_str(), Point::ZERO, COLOR_WHITE, 10);
	}

	// fpsの文字表示後に画面更新をする
	if(_waitCallBack)
	{
		_waitCallBack();
	}

	// fps調節のために、一定時間とめる
	if(isDrawFPS)
	{
		if(_fps > DefaultFPS)
		{
			int waitTime = _frameCount * 1000 / DefaultFPS - elapsedTime;	//待つべき時間
			if(waitTime > 0)
			{
				Sleep(waitTime);	//待機
			}
		}

		_frameCount = 0;
	}

	return true;
}

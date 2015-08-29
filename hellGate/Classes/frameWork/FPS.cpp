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

	//1�t���[���ڂȂ玞�����L��
	if(_frameCount == 0)
	{
		_startTime = GetNowCount();
		_frameCount++;
	}
	//60�t���[���ڂȂ畽�ς��v�Z����
	else if(_frameCount >= DefaultFPS)
	{
		float finishTime = GetNowCount();
		elapsedTime = (finishTime - _startTime);
		_fps = 1000.f / (elapsedTime / DefaultFPS);

		isDrawFPS = true;
	}
	// ����ȊO�Ȃ�Acount�����Z
	else
	{
		_frameCount++;
	}

	// ���x���\��
	if(_fps != 0.0f)
	{
		const std::string& str = fw::getStrWithFormat("fps: %.1f", _fps);
		fw::DrawLabel(str.c_str(), Point::ZERO, COLOR_WHITE, 10);
	}

	// fps�̕����\����ɉ�ʍX�V������
	if(_waitCallBack)
	{
		_waitCallBack();
	}

	// fps���߂̂��߂ɁA��莞�ԂƂ߂�
	if(isDrawFPS)
	{
		if(_fps > DefaultFPS)
		{
			int waitTime = _frameCount * 1000 / DefaultFPS - elapsedTime;	//�҂ׂ�����
			if(waitTime > 0)
			{
				Sleep(waitTime);	//�ҋ@
			}
		}

		_frameCount = 0;
	}

	return true;
}

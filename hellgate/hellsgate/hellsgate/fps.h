/*
fps��������p�N���X
2014.08.31 tanaka_hiroki
 */
#ifndef __FPS__H__
#define __FPS__H__

#include <math.h>
#include "hellsgate.h"

#define FPS (60)	//�ݒ肵��FPS

class fps
{
public:
	fps();
	virtual ~fps();
	void init();

	static bool Update();
	static void Draw();
	static void Wait();
private:
	static int mStartTime;  //����J�n����
	static int mCount;      //�J�E���^
	static float mFps;      //fps
};

#endif

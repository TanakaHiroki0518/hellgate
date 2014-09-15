/*
fps上限制限用クラス
2014.08.31 tanaka_hiroki
 */
#ifndef __FPS__H__
#define __FPS__H__

#include <math.h>
#include "hellsgate.h"

#define FPS (60)	//設定したFPS

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
	static int mStartTime;  //測定開始時刻
	static int mCount;      //カウンタ
	static float mFps;      //fps
};

#endif

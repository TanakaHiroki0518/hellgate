/*
fps調整
 */
#ifndef __FPS_H__
#define __FPS_H__

#include <iostream>
#include <DxLib.h>

#define FPS  60.0f //設定したFPS
#define MM_CONVERT_TIME 1000.0f // ミリ秒から秒への変換用

class fps
{
public:
	// コンストラクタ
	fps();
	// デストラクタ
	virtual ~fps();

	// 初期化
	void init();
	// update
	bool update();

	// fpsの表示非表示切り替え
	void isVisibleFPS(bool isVisible) { this->m_isVisible = isVisible; };
private:
	void draw();
	void wait();

private:
	float m_StartTime; //測定開始時刻
	float m_Count; //カウンタ
	float m_Fps; //fps
	bool m_isVisible; // fpsの表示非表示
};

#endif /*__FPS_H__*/

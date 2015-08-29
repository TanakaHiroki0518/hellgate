/*
 * FPS.h
 * 2015/08/23 tanaka.h
 */
#include	"hellsgate.h"

USE_NS_FW

/**
 * @brief fps調整用クラス
 * @brief 60フレーム毎に時間を計測後、調整
 */
class FPS
{
public:
	static FPS* getInstance();
	static void deleteInstance();

	bool update();

protected:
	FPS(){};
	virtual ~FPS(){};

protected:
	static FPS* _instance;
	const float DefaultFPS = 60.0f;

private:
	FW_SYNTHESIZE(std::function<int()>, _waitCallBack, WaitCallBack); // wait用コールバック
	FW_SYNTHESIZE_WITHINIT(int, _frameCount, FrameCount, 0);// フレームカウント
	FW_SYNTHESIZE_WITHINIT(int, _startTime, StartTime, 0);	// 計測開始時間
	FW_SYNTHESIZE_WITHINIT(float, _fps, Fps, 0.0f); // fps
};

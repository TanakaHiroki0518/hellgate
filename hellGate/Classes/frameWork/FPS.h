/*
 * FPS.h
 * 2015/08/23 tanaka.h
 */
#include	"hellsgate.h"

USE_NS_FW

/**
 * @brief fps�����p�N���X
 * @brief 60�t���[�����Ɏ��Ԃ��v����A����
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
	FW_SYNTHESIZE(std::function<int()>, _waitCallBack, WaitCallBack); // wait�p�R�[���o�b�N
	FW_SYNTHESIZE_WITHINIT(int, _frameCount, FrameCount, 0);// �t���[���J�E���g
	FW_SYNTHESIZE_WITHINIT(int, _startTime, StartTime, 0);	// �v���J�n����
	FW_SYNTHESIZE_WITHINIT(float, _fps, Fps, 0.0f); // fps
};

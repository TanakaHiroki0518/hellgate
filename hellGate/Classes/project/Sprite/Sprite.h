/*
 * Sprite.h
 * 2015/08/22 tanaka.h
 */
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "../../frameWork/hellsgate.h"

USE_NS_FW

struct splitIdx
{
	int x = 0;
	int y = 0;
};

struct graphData
{
	const char* lpszName = "";
	bool isAlphaEnabled = false;
	int sizeH = 0;
	int sizeW = 0;
	int allNum = 0;
	int countX = 0;
	int countY = 0;
};

/**
 * @brief DxLib����global�ȉ摜��tag
 * @brief key = y���Windex
 * @brief value = x���Wtag�z��
 */
typedef std::map<int, std::vector<int>> GraphTagMap;

class Sprite
{
public:
	static Sprite* create(graphData data);

	int getAllGraphNum();

protected:
	Sprite();
	virtual ~Sprite();

	// �摜�̕\���ʒu
	FW_SYNTHESIZE_WITHINIT(int, _pointX, PointX, 0);		// X���W
	FW_SYNTHESIZE_WITHINIT(int, _pointY, PointY, 0);		// Y���W
	FW_SYNTHESIZE_WITHINIT(int, _zorder, Zorder, 0);		// �摜�̕\���[�x

	// �摜�T�C�Y
	FW_SYNTHESIZE_WITHINIT(int, _sizeH, SizeH, 0);			// �摜�̍���
	FW_SYNTHESIZE_WITHINIT(int, _sizeW, SizeW, 0);			// �摜�̉���

	// �摜tag��map
	FW_SYNTHESIZE(GraphTagMap, _graphTag, GraphTag);

	// �\�����̉摜�̔ԍ�
	FW_SYNTHESIZE(splitIdx, _nowShowIdx, NowShowIdx);

	// �\�����
	FW_SYNTHESIZE_WITHINIT(bool, _visible, Visible, false);	// �\���E��\��
	FW_SYNTHESIZE_WITHINIT(bool, _isAlphaEnabled, IsAlphaEnabled, false);	// ���߂̗L���E����
};

#endif /*__SPRITE_H__*/

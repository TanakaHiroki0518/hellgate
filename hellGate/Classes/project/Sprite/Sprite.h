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
 * @brief DxLib内でglobalな画像のtag
 * @brief key = y座標index
 * @brief value = x座標tag配列
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

	// 画像の表示位置
	FW_SYNTHESIZE_WITHINIT(int, _pointX, PointX, 0);		// X座標
	FW_SYNTHESIZE_WITHINIT(int, _pointY, PointY, 0);		// Y座標
	FW_SYNTHESIZE_WITHINIT(int, _zorder, Zorder, 0);		// 画像の表示深度

	// 画像サイズ
	FW_SYNTHESIZE_WITHINIT(int, _sizeH, SizeH, 0);			// 画像の高さ
	FW_SYNTHESIZE_WITHINIT(int, _sizeW, SizeW, 0);			// 画像の横幅

	// 画像tagのmap
	FW_SYNTHESIZE(GraphTagMap, _graphTag, GraphTag);

	// 表示中の画像の番号
	FW_SYNTHESIZE(splitIdx, _nowShowIdx, NowShowIdx);

	// 表示情報
	FW_SYNTHESIZE_WITHINIT(bool, _visible, Visible, false);	// 表示・非表示
	FW_SYNTHESIZE_WITHINIT(bool, _isAlphaEnabled, IsAlphaEnabled, false);	// 透過の有効・無効
};

#endif /*__SPRITE_H__*/

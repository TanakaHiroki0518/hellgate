/*
 * Sprite.cpp
 * 2015/08/22 tanaka.h
 */
#include "Sprite.h"

// コンストラクタ・デストラクタ
Sprite::Sprite()
{
}
Sprite::~Sprite()
{
}

Sprite* Sprite::create(graphData data)
{
	Sprite* spr = new Sprite();

	// 画像数が複数なら、LoadDivGraph
	if(data.allNum > 1)
	{

	}
	// 画像数が単一だから、LoadGraph
	else
	{

	}

	return spr;
}

int Sprite::getAllGraphNum()
{
	int allNum = 0;
	for(auto it : _graphTag)
	{
		// map内の全ての配列sizeを加算
		allNum += it.second.size();
	}
	return allNum;
}

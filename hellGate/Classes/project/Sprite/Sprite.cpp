/*
 * Sprite.cpp
 * 2015/08/22 tanaka.h
 */
#include "Sprite.h"

// �R���X�g���N�^�E�f�X�g���N�^
Sprite::Sprite()
{
}
Sprite::~Sprite()
{
}

Sprite* Sprite::create(graphData data)
{
	Sprite* spr = new Sprite();

	// �摜���������Ȃ�ALoadDivGraph
	if(data.allNum > 1)
	{

	}
	// �摜�����P�ꂾ����ALoadGraph
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
		// map���̑S�Ă̔z��size�����Z
		allNum += it.second.size();
	}
	return allNum;
}

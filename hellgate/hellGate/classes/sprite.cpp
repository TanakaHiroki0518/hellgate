/*
sprite格納クラス
 */
#include "sprite.h"

// 親パス
#define GRAPHICS "resources\\graphic\\"

// コンストラクタ
sprite::sprite()
: m_spr(NULL)
{
}

// デストラクタ
sprite::~sprite()
{
	delete[] m_spr;
}

// create
void sprite::createWithNode(const char* nodePath)
{
	// create
	m_spr = new spriteStatus();

	// 画像のロード
	m_spr->graphic = LoadGraph((const wchar_t*)this->convertGraPath(nodePath));
}

bool sprite::init()
{
	// spriteStatus内すべての変数の初期化
	m_spr->graphic = 0;
	m_spr->isVisible = false;
	m_spr->pos_x = 0;
	m_spr->pos_y = 0;
	m_spr->zOrder = 0;
	m_spr->height = 0;
	m_spr->width = 0;
	m_spr->allnum = 0;
	m_spr->x_num = 0;
	m_spr->y_num = 0;
	m_spr->nAlpha = 0;

	return true;
}

const char* sprite::convertGraPath(const char* path)
{
	// 親パス
	std::string str = GRAPHICS;
	// 子パスの追加
	str.append(path);

	return str.c_str();
}

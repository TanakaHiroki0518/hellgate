/*
sprite取り扱いクラス
 */
#ifndef __SPRITE__H__
#define __SPRITE__H__

#include <iostream>
#include <DxLib.h>

// スプライトのステータス構造体
struct spriteStatus
{
public:
	// 画像格納用
	int graphic;
	// 表示非表示
	bool isVisible;	// true=表示, false=非表示
	// 座標
	int	pos_x;		// x座標
	int	pos_y;		// y座標
	// 深度
	int	zOrder;		// 画像の表示深度(0 = 画面最前面, 65535 = 画面最深部)
	// スプライトサイズ
	int	height;		// 画像の高さ
	int	width;		// 画像の幅
	// アニメーション用分割数
	int allnum;		// 分割数
	int x_num;		// 横分割数
	int y_num;		// 縦分割数
	// 透明度
	int	nAlpha;		// 透過色指定
};

class sprite
{
public:
	// コンストラクタ, デストラクタ
	sprite();
	virtual ~sprite();

	// create
	void createWithNode(const char* nodePath);
private:
	bool init();
	const char* convertGraPath(const char* path);
private:
	spriteStatus* m_spr;
};

#endif /*__SPRITE__H__*/

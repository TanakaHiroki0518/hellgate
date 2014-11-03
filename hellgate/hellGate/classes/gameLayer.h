/*
汎用シーンクラス
 */

#ifndef __GAME_LAYER__H__
#define __GAME_LAYER__H__

#include <DxLib.h>
#include <iostream>
#include <map>

class gameLayer
{
public:
	// コンストラクタ
	gameLayer();
	// デストラクタ
	virtual ~gameLayer();

	// シーンに入ってきた時に実行される
	virtual onEnter();
	// シーンを出た時に実行される
	virtual onExit();

	// 画像を格納
	virtual addChild();
	virtual addChild(std::string tag);
private:
};


#endif /*__GAME_LAYER__H__*/

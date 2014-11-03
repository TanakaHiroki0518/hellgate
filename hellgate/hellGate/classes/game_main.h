/*
ゲームのメイン
 */
#ifndef __GAME_MAIN__H__
#define __GAME_MAIN__H__

#include <iostream>
#include <DxLib.h>
#include "fps\fps.h"

#define KEY_MAX 256


enum keyPress
{
	disable = 0, // 押していない
	enable, // 押した瞬間
	keepEnable, // 押し続けている
};

class game_main
{
// 関数
public:
	// コンストラクタ, デストラクタ
	game_main();
	virtual ~game_main();

	// ゲームメイン
	void GameMain();
private:
	// キー判定
	int m_GetHitKeyStateAll();
	// システム処理
	bool systemProcess();
	// 描画処理
	void DrawProcess();
	// ゲーム初期化処理
	void GameInit();
	// ゲーム終了
	void GameEnd();
// 変数
public:
private:
	char m_Key[KEY_MAX]; // キー判定用
	fps fps; // fps調整用
};


#endif /*__GAME_MAIN__H__*/

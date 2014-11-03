/*
ゲームメイン
 */

#include "game_main.h"
#include "common\resourcesCommon.h"

// コンストラクタ
game_main::game_main()
{
}

// デストラクタ
game_main::~game_main()
{
}

// ゲームメイン
void game_main::GameMain()
{
	// TRUE = ウィンドウモード, FALSE = フルスクリーン
	ChangeWindowMode(TRUE);
	
	// 解像度(int width, int height), 表示限度色数(int colorNum), fps(=60)
	SetGraphMode(WINDOW_SIZE_W,WINDOW_SIZE_H,WINDOW_COLOR);

	// ウィンドウ表示に例外 or dxlibの初期化ミス
	if( ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK || DxLib_Init() == -1 )
	{
		// エラーなので終了処理
		return;
	}

	// 裏画面に設定(黒画面)
    SetDrawScreen( DX_SCREEN_BACK );
	
	// ゲームの初期化処理
	this->GameInit();

	// 何らかのエラーを感知 or escキーが押されるまでループ
	while(true)
	{
		// エラー検出
		if(!this->systemProcess())
		{
			break;
		}

		// ゲーム処理

		// 描画処理
		this->DrawProcess();
	}

	// 終了処理
	this->GameEnd();
	
	return;
}

// ゲーム初期化
void game_main::GameInit()
{
	// fpsの初期化
	fps.init();

	// fpsの表示非表示切り替え(true = 表示, false = 非表示)
	fps.isVisibleFPS(true);

	return;
}

// ゲーム終了
void game_main::GameEnd()
{
	// BGM, SEの停止
	StopMusic();
	//	描画管理モジュール・終了

	//	DXライブラリ・終了
	DxLib_End();

	return;
}

// システム処理
bool game_main::systemProcess()
{
	// プロセスメッセージ
	ProcessMessage();

	//	画面を初期化
	ClearDrawScreen();

	// キー判定
	this->m_GetHitKeyStateAll();

	// escキーで終了
	if(m_Key[KEY_INPUT_ESCAPE] != keyPress::disable)
	{
		// escキーが押された
		return false;
	}
	
	return true;
}

// 描画処理
void game_main::DrawProcess()
{
	//fps調整
	fps.update();
	
	// 裏画面と表画面を入れ替える
	ScreenFlip();

	return;
}

// キー入力判定
int game_main::m_GetHitKeyStateAll()
{
	// 押されているキーの取得
	char GetHitKeyStateAll_Key[KEY_MAX];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );

	// キーのステータス格納
	for(int i = 0; i != KEY_MAX; i++)
	{
		if(GetHitKeyStateAll_Key[i] >= keyPress::enable)
		{
			// 押し続けている
			this->m_Key[i] = keyPress::keepEnable;
		}
		else if(GetHitKeyStateAll_Key[i] != keyPress::disable)
		{
			// 押された瞬間
			this->m_Key[i] = keyPress::enable;
		}
		else
		{
			// 指定したキーは押されていない
			this->m_Key[i] = keyPress::disable;
		}
	}

	return 0;
}


//=======================================================================================
//			メイン関数
//			制作年/月/日		制作者
//			  2014/11/2			H.tanaka
//=======================================================================================
#include <Windows.h>
int WINAPI WinMain(
  HINSTANCE hInstance,      // 現在のインスタンスのハンドル
  HINSTANCE hPrevInstance,  // 以前のインスタンスのハンドル
  LPSTR lpCmdLine,          // コマンドライン
  int nCmdShow              // 表示状態
)
{
	// ゲームメイン関数の呼び出し
	game_main main;
	main.GameMain();

	return	0;
}

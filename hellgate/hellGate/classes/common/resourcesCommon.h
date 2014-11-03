/*
 リソースパス格納ヘッダ
 */
#ifndef __RESOURCES_COMMON__H__
#define __RESOURCES_COMMON__H__

#include <DxLib.h>

//-----------------------------------------------------
// 画像やBGM,SE
//-----------------------------------------------------
// graphic

// sound
#define SOUNDS "resources\\sound\\"
#define MAIN_BGM "game_main.mp3"

//-----------------------------------------------------
// color
//-----------------------------------------------------
#define cWhite GetColor(255, 255, 255)

//-----------------------------------------------------
// ウィンドウ
//-----------------------------------------------------
#define WINDOW_SIZE_W 640
#define WINDOW_SIZE_H 480
#define WINDOW_COLOR 16

#endif /*__RESOURCES_COMMON__H__*/

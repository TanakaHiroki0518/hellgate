
#ifndef	__HELLGATE_H__
#define	__HELLGATE_H__

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <DxLib.h>
#include "Point.h"
#include <cstdarg>

//====================================================================================
//			構造体の宣言
//			制作年/月/日		制作者
//			  2012/10/29		H.tanaka
//====================================================================================

//	画面サイズ
#define	WINDOW_SIZE_W			(800)	//	横
#define	WINDOW_SIZE_H			(600)	//	縦
#define	WINDOW_COLOR			(16)	//	色
#define	PL_GRAPH_SIZE			(32)	//	自機グラフィックサイズ


#define	ADV_MAX_MAIN	(2048)	//画像表示制限
#define	ADV_MAX_Z		(65535)	//画像最高深度

#define	GRA_ON			(1)		//画像表示
#define	GRA_OFF			(0)		//画像非表示

#define	s_speed			(20)	//背景スクロール速度

#define	map_h			(18)	//マップマス数
#define	map_w			(24)
#define maptip_size		(32)

#define map_waku_x		(16)	//マップの外枠
#define map_waku_y		(12)

#define map_speed		(16)
#define player_speed	(16)


#define map_num			(38)	//マップチップの種類

#define ya_x			(565)	//メニュー画面のアイコンの初期位置
#define ya_y			(27)
#define ya2_x			(20)
#define ya2_y			(425)
#define Witop_x			(550)
#define Widown_y		(400)
#define Wi_x			(650)
#define Wi_y			(300)

//=========================================================
//		自機ステータス
//=========================================================
#define player_hp		(100)
#define player_atp		(1)
#define player_blp		(1)

//=========================================================
//		敵機ステータス
//=========================================================
#define kobuta			(7)
#define enemy_h			(4)
#define enemy_w			(2)
#define enemy_hp		(3)
#define enemy_atp		(10)
#define enemy_blp		(0)
#define enemy_koshika	(35)

//=========================================================
//	マクロ
//=========================================================
namespace fw
{
	/**
	 * @brief メンバ変数定義用マクロ
	 * @param[in] varType メンバ変数のデータ型
	 * @param[in] varName メンバ変数の名前
	 * @param[in] funcName メンバ関数getterやsetterの名前
	 */
#define FW_SYNTHESIZE(varType, varName, funcName) \
private: \
	varType varName; \
public: \
	void set##funcName(varType var) { varName = var; }; \
	varType get##funcName() { return varName; };

	// getterのみ
#define FW_SYNTHESIZE_READONLY(varType, varName, funcName) \
private: \
	varType varName; \
public: \
	varType get##funcName() { return varName; };

	// 初期化有
#define FW_SYNTHESIZE_WITHINIT(varType, varName, funcName, initVar) \
private: \
	varType varName = initVar; \
public: \
	void set##funcName(varType var) { varName = var; }; \
	varType get##funcName() { return varName; };

	// getterのみ、初期化有
#define FW_SYNTHESIZE_WITHINIT_READONLY(varType, varName, funcName, initVar) \
private: \
	varType varName = initVar; \
public: \
	varType get##funcName() { return varName; };

	// ポインタ用
#define FW_SYNTHESIZE_POINTER(varType, varName, funcName) FW_SYNTHESIZE_WITHINIT(varType##*, varName, funcName, nullptr)

#define FW_SYNTHESIZE_POINTER_READONLY(varType, varName, funcName) FW_SYNTHESIZE_WITHINIT_READONLY(varType##*, varName, funcName, nullptr)

	// 関数格納用
#define FW_CALLBACK_0(__selector__) std::bind(&__selector__)
#define FW_CALLBACK_1(__selector__) std::bind(&__selector__, std::placeholders::_1)
#define FW_CALLBACK_2(__selector__) std::bind(&__selector__, std::placeholders::_1, std::placeholders::_2)
#define FW_CALLBACK_3(__selector__) std::bind(&__selector__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)

	// 色
#define COLOR_WHITE GetColor(255, 255, 255)

	//	DXライブラリ・描画
	inline int Draw(int x, int y, int gHandle, bool isAlpha)
	{
		int alpha = isAlpha ? TRUE : FALSE;
		return DrawGraph(x, y, gHandle, alpha);
	}

	inline std::string strPrintfWithFormat(const char* format, std::va_list arg){
		std::string ret;
		ret.resize(32); // この値は根拠なし。もう少し大きくても良いかもしれない。
		auto n = static_cast<std::size_t>(vsnprintf(&ret[0], ret.size(), format, arg));

		if(n == static_cast<std::size_t>(-1)){
			n = _vscprintf(format, arg) + 1;
			ret.resize(n + 1);
			n = vsnprintf(&ret[0], ret.size(), format, arg);
		}
		ret.resize(n);
		return ret;
	}

	inline std::string getStrWithFormat(const char* fmt, ...){
		std::va_list varList;
		va_start(varList, fmt);
		std::string buf = strPrintfWithFormat(fmt, varList);
		va_end(varList);
		return buf;
	};

	inline int DrawLabel(const char* str, Point point, DWORD color, int fontSize = 20)
	{
		SetFontSize(fontSize);
		return DrawFormatString(point.x, point.y, color, str);
	}
}
#define USE_NS_FW using namespace fw;

typedef struct
{
	int png;
}
MAP_MAIN;


typedef	struct
{
	int	bUsed;		//	使用状態
	int	nAlpha;		//	透過色指定
	int	sprNo[4];		//	素材番号
	int	x;			//	x座標
	int	y;			//	y座標
	int	z;			//	画像の表示深度
	int	h;			//	画像の高さ
	int	w;			//	画像の幅
	int	g_show;		//	画像使用1=使用、0=未使用
	int allnum;		//	画像の分割数
	int x_num;		//	画像の横分割数
	int y_num;		//	画像の縦分割数
	int show_num;	//	表示中の画像の番号
	int dmg;
}
ADV_MAIN;

typedef struct
{
	int x;
	int y;
	int hp;
	int max_hp;
	int atp;
	int blp;
	int move_c;
	int dmg;
}
CHARA_MAIN;


//====================================================================================
//			関数の宣言
//			制作年/月/日		制作者
//			  2012/10/26		H.tanaka
//====================================================================================
//init.cpp
void gamemain(void);
ADV_MAIN* spr_create(const char* lpszName, long nAlpha, int graph_h, int graph_w, int allnum, int xnum, int ynum);
void SprDestroy(ADV_MAIN *lpSpr);
void SprFinish(void);
void SprDraw(void);
void SprSetPos(ADV_MAIN *lpSpr, long nX, long nY);
void SprGetPos(ADV_MAIN *lpSpr, long *lpX, long *lpY);
void SprSetDepth(ADV_MAIN *lpSpr, long nZ);
void SprMove(ADV_MAIN *lpSpr, long nX, long nY);
void SprShow(ADV_MAIN *lpSpr, long nShow);
void SprGetSize(ADV_MAIN *lpSpr, long *lpW, long *lpH);
void graph_shownum(ADV_MAIN	*lpspr);

//main.cpp


//map.cpp
void	MapMain(int map_c,int scroll,ADV_MAIN *lpspr);
void	MapGraphLoad(void);
void	MapInit(void);
void	atari_wall(ADV_MAIN	*lpspr,CHARA_MAIN	player,int map_c);
int atari_damage(ADV_MAIN *lpspr, int map_c);
int		damage_trap(ADV_MAIN	*lpspr,CHARA_MAIN player,int map_c);
int	damage_trap_enemy(ADV_MAIN	*lpspr,CHARA_MAIN enemy,int map_c);
int key_main(ADV_MAIN *lpspr, int map_c);


//string.cpp
void	String_Draw(CHARA_MAIN	player,int string_c);

//fps.cpp
bool Update();
void Draw(void);
void Wait(void);

//player.cpp
int		player_move(ADV_MAIN	*lpsprPl,CHARA_MAIN	player,char Key[256]);
void	saykim(ADV_MAIN	*lpspr,CHARA_MAIN chara);
int Baphomet_hp(ADV_MAIN *lpsprBap,CHARA_MAIN player);
int	Baphomet_item();
void	player_bug(ADV_MAIN	*lpspr,CHARA_MAIN player);

//enemy.cpp
int		enemy_main(ADV_MAIN	*lpsprEn[enemy_h][enemy_w],ADV_MAIN *lpsprPl,CHARA_MAIN player,int map_c,int dash_c,ADV_MAIN *lpsprGate);
void	sayenemy(ADV_MAIN *lpsprEn,ADV_MAIN *lpspr,CHARA_MAIN enemy);
void	enemy_init(ADV_MAIN *lpspr[enemy_h][enemy_w],int game_c,int map_c);
void	enemy_seigyo(ADV_MAIN *lpsprEn[enemy_h][enemy_w]);

//gate.cpp
int		gate_main(ADV_MAIN	*lpsprGate,int dash_c,ADV_MAIN	*lpsprPl,CHARA_MAIN player,char Key[256],int map_c);

#endif	/*__HELLGATE_H__*/

/*
汎用データ格納用ヘッダ
 */

#ifndef __COMMON_DATA__H__
#define __COMMON_DATA__H__

//	画面サイズ
#define	WINDOW_SIZE_W			(800)	//	横
#define	WINDOW_SIZE_H			(600)	//	縦
#define	WINDOW_COLOR			(16)	//	色
#define	PL_GRAPH_SIZE			(32)	//	グラフィックサイズ


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
//		色
//=========================================================
#define WHITE GetColor(255,255,255) // 白

// マップチップ用画像格納構造体
typedef struct
{
	int png;
} MAP_MAIN;

// 画像ステータス
typedef	struct
{
	int	bUsed;		//	使用状態
	int	nAlpha;		//	透過色指定
	int	sprNo[4];	//	素材番号
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
} ADV_MAIN;

// キャラステータス
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
} CHARA_MAIN;

#endif /* __COMMON_DATA__H__ */

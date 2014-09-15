
#ifndef	SHTD_SPRITE_HEADER_INCLUDED_
#define	SHTD_SPRITE_HEADER_INCLUDED_

#include "commonData.h"
#include "commonResources.h"

//====================================================================================
//			ç\ë¢ëÃÇÃêÈåæ
//			êßçÏîN/åé/ì˙		êßçÏé“
//			  2012/10/29		H.tanaka
//====================================================================================


//====================================================================================
//			ä÷êîÇÃêÈåæ
//			êßçÏîN/åé/ì˙		êßçÏé“
//			  2012/10/26		H.tanaka
//====================================================================================
#ifdef	__cplusplus
extern	"C"
{
#endif	//	__cplusplus

//init.cpp
void	gamemain(void);
ADV_MAIN	*spr_create(wchar_t *lpszName,long nAlpha,int graph_h,int graph_w,int allnum,int xnum,int ynum);
void	SprDestroy(ADV_MAIN *lpSpr);
void	SprFinish(void);
void	SprDraw(void);
void	SprSetPos(ADV_MAIN *lpSpr, long nX, long nY);
void	SprGetPos(ADV_MAIN *lpSpr, long *lpX, long *lpY);
void	SprSetDepth(ADV_MAIN *lpSpr, long nZ);
void	SprMove(ADV_MAIN *lpSpr, long nX, long nY);
void	SprShow(ADV_MAIN *lpSpr, long nShow);
void	SprGetSize(ADV_MAIN *lpSpr, long *lpW, long *lpH);
void	graph_shownum(ADV_MAIN	*lpspr);

//main.cpp


//map.cpp
void	MapMain(int map_c,int scroll,ADV_MAIN *lpspr);
void	MapGraphLoad(void);
void	MapInit(void);
void	atari_wall(ADV_MAIN	*lpspr,CHARA_MAIN	player,int map_c);
int		atari_damage(ADV_MAIN	*lpspr,CHARA_MAIN player,int map_c);
int		damage_trap(ADV_MAIN	*lpspr,CHARA_MAIN player,int map_c);
int	damage_trap_enemy(ADV_MAIN	*lpspr,CHARA_MAIN enemy,int map_c);
int		key_main(CHARA_MAIN player,ADV_MAIN *lpspr,char Key[256],int map_c);


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




#ifdef	__cplusplus
}
#endif	//	__cplusplus

#endif	//	!defined(SHTD_SPRITE_HEADER_INCLUDED_)

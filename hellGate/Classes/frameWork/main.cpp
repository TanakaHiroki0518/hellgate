#include "../frameWork/hellsgate.h"
#include "../frameWork/FPS.h"



//====================================================================================
//			キー入力判定
//			制作年/月/日		制作者
//			  2012/10/26		H.tanaka
//====================================================================================
char Key[256];

int GetHitKeyStateAll_2(int GetHitKeyStateAll_InputKey[])
{
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );
	for(int i=0;i<256;i++)
	{
		if(GetHitKeyStateAll_Key[i]==1)
		{
			GetHitKeyStateAll_InputKey[i]++;
		}
		else
		{
			GetHitKeyStateAll_InputKey[i];
		}
	}
	return 0;
}


//=======================================================================================
//			変数の宣言・初期化
//			制作年月日			制作者
//			2013/01/20			H.tanaka
//=======================================================================================
int	scr_c;
int	koshika;
int	game_c;
int	menue_c;
int menue_koshika;
int map_c;
int scroll;
int string_c;
int say;
int dt;
int graph_h;
int graph_w;
int allnum;
int xnum;
int ynum;
int i;
int e;
int play_c;
int st_c;
int bap_c;
int dash_c;


//	画像読み込み
CHARA_MAIN	player;
CHARA_MAIN	gate;
ADV_MAIN	*lpsprBlk;
ADV_MAIN	*lpsprend;
ADV_MAIN	*lpsprGate;
ADV_MAIN	*lpsprTi;
ADV_MAIN	*lpsprEn[enemy_h][enemy_w];
ADV_MAIN	*lpsprPl;	//	自機
ADV_MAIN	*lpsprBap;
ADV_MAIN	*lpsprMn;	//	メニュー画面
ADV_MAIN	*lpsprMn_down;
ADV_MAIN	*lpsprMn_up;
ADV_MAIN	*lpsprYa;	//	メニュー画面・アイコン
ADV_MAIN	*lpsprYa2;
ADV_MAIN	*lpsprWi;
ADV_MAIN	*lpsprStar;
//====================================================================================
//			関数呼び出し用
//			制作年/月/日		制作者
//			  2012/10/30		H.tanaka
//====================================================================================
int	menue_main(ADV_MAIN	*lpspr,ADV_MAIN	*lpsprYa,ADV_MAIN	*lpsprYa2,ADV_MAIN	*lpsprWi,CHARA_MAIN	player);
void	fpscounter(void);
void	game_end(void);
void	player_scroll(void);
int		game_init();
int		title();
int		prologue();
void	player_hantei(void);
void	Baphomet_main(void);
void	enemy_seigyo(void);

//=======================================================================================
//			メイン関数
//			制作年/月/日		制作者
//			  2012/10/26		H.tanaka
//=======================================================================================
int	WINAPI	WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_SIZE_W,WINDOW_SIZE_H,WINDOW_COLOR);
	if( ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK || DxLib_Init() == -1 )
	{
		return -1; //初期化失敗
	}
    SetDrawScreen( DX_SCREEN_BACK ); // 裏画面に設定
	FPS::getInstance()->setWaitCallBack(FW_CALLBACK_0(DxLib::ScreenFlip)); // 表示する画面をひっくりかえす
	
	while(!ProcessMessage() && !ClearDrawScreen() && !GetHitKeyStateAll( Key ) && !Key[KEY_INPUT_ESCAPE])
	{
              //↑ﾒｯｾｰｼﾞ処理         ↑画面をｸﾘｱ          ↑ｷｰﾎﾞｰﾄﾞ入力状態取得       ↑ESCが押されていない
		//	画面を初期化
		ClearDrawScreen();
		//	タイトル前準備
		if(game_c == 0)
		{
			game_init();
			SprShow(lpsprTi,GRA_ON);
			SprSetPos(lpsprYa,265,330);
			SprShow(lpsprYa,GRA_ON);
			game_c = 1;
		}
		//	タイトル
		else if(game_c == 1)
		{
			game_c = title();
			if(game_c == 2)
			{
				st_c	 = 0;
				SprShow(lpsprTi,GRA_OFF);
				SprShow(lpsprYa,GRA_OFF);
				if(lpsprYa->y == 330)
				{
					SprShow(lpsprMn_down,GRA_ON);
					string_c = 1;
					play_c = 0;
				}
				else if(lpsprYa->y == 330+55)
				{
					play_c = 1;
					//セーブデータのロード
				}
			}
		}
		//	ゲームメイン
		else if(game_c == 2)
		{
			if(play_c == 0)
			{
				string_c = prologue();
				if(( Key[KEY_INPUT_DOWN] == 1 ) && (string_c != 0))
				{
					string_c++;
				}
				if((string_c >= 15)	&&	(string_c < 17))
				{
					SprShow(lpsprend,GRA_ON);
				}
				else if(string_c >= 18)
				{
					SprShow(lpsprend,GRA_OFF);
				}
				else if(string_c == 0)
				{
					SprShow(lpsprMn_down,GRA_OFF);
					SprShow(lpsprend,GRA_OFF);
					play_c++;
				}
			}
			if(play_c == 1)
			{
				//------------------------------------------------------------------------------------
				//		主人公能力初期設定
				//		2013.01.18
				//------------------------------------------------------------------------------------
				player.atp		=	player_atp;		//主人公攻撃力（初期値1）
				player.blp		=	player_blp;		//主人公防御力（初期値1）
				player.max_hp	=	player_hp;
				player.hp		=	player.max_hp;	//主人公HP（初期値100）
				player.move_c	=	0;		//縦方向向いている向き
				player.dmg		=	0;
				dash_c = 0;
				play_c++;
			}
			if(play_c == 2)
			{
				SprShow(lpsprPl,GRA_ON);
				MapGraphLoad();
				MapInit();
				//PlayMusic("sound/game_sound.MP3",DX_PLAYTYPE_LOOP);
				SetVolumeMusic(1);
				map_c	= 2;
				enemy_init(lpsprEn,game_c,map_c);
				game_c = 3;
			}
		}
		else if(game_c == 3)
		{
			player.x		=	lpsprPl->x;
			player.y		=	lpsprPl->y;
			//自機の移動
			if(scr_c == 0)
			{
				if(say == 0)
				{
					if((lpsprEn[0][0]->dmg == 0) && (lpsprEn[0][1]->dmg == 0) && (lpsprEn[1][0]->dmg == 0) && (lpsprEn[1][1]->dmg == 0))
					{
						player.move_c = player_move(lpsprPl,player,Key);
						player_hantei();
						if(game_c == 7)
						{
							continue;
						}
						player.hp = damage_trap(lpsprPl,player,map_c);
						say = atari_damage(lpsprPl,map_c);
						if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
						{
							game_c	=	10;
							menue_c	=	0;
						}
					}
				}
				else if(dt < 5)
				{
					saykim(lpsprPl,player);
					dt++;
				}
				else if(dt >= 5)
				{
					say = dt = 0;
				}
				player.hp = enemy_main(lpsprEn,lpsprPl,player,map_c,dash_c,lpsprGate);
				enemy_seigyo(lpsprEn);
				if(map_c != 1)
				{
					if((map_c / 10 == 0) || (map_c / 10 == 1))
					{
						for(i = 0;i < enemy_h;i++)
						{
							for(e = 0;e < enemy_w;e++)
							{
								SprShow(lpsprEn[i][e],GRA_ON);
								if((i >= 2) || (e >= 2))
								{
									SprShow(lpsprEn[i][e],GRA_OFF);
								}
							}
						}
					}
				}
			}
			else
			{
				player_scroll();
				enemy_init(lpsprEn,game_c,map_c);
				SprShow(lpsprStar,GRA_OFF);
			}

			
			
			if(player.hp	<=	0)
			{
				SprFinish();
				StopMusic();
				game_c = 0;
			}
			//バフォメット（回復・よろず屋）
			if((map_c == 12)	&&	(lpsprPl->y <= (lpsprBap->y + maptip_size)+10))
			{
				if((lpsprPl->x < (lpsprBap->x + maptip_size)) &&((lpsprPl->x + maptip_size) > lpsprBap->x))
				{
					if((Key[KEY_INPUT_Z] != 0) && (menue_c >= 19))
					{
						menue_c = 0;
						bap_c = 1;
						SprShow(lpsprMn_down,GRA_ON);
						SprShow(lpsprWi,GRA_ON);
						SprShow(lpsprYa2,GRA_ON);
						lpsprYa2->x	= Wi_x + 30;
						lpsprYa2->y	= Wi_y + 20;
						string_c = 103;
						game_c = 5;
					}
				}
			}
			else
			{
				bap_c = 0;
			}

			

			if((Key[KEY_INPUT_UP]	!=	0) || (Key[KEY_INPUT_DOWN]	!=	0) || 
				(Key[KEY_INPUT_RIGHT]	!=	0) || (Key[KEY_INPUT_LEFT]	!=	0) || 
				(lpsprEn[0][0]->dmg !=0) || (lpsprEn[0][1]->dmg !=0) || (lpsprEn[1][0]->dmg !=0) || (lpsprEn[1][1]->dmg !=0))
			{
				graph_shownum(lpsprPl);
			}
			if((Key[KEY_INPUT_UP]	==	0) && (Key[KEY_INPUT_DOWN]	==	0) && 
				(Key[KEY_INPUT_RIGHT]	==	0) && (Key[KEY_INPUT_LEFT]	==	0) && (scr_c != 0))
			{
				lpsprPl->show_num	= 0;
				//制御用関数
				if(scr_c == 0)
				{
					player_bug(lpsprPl,player);
				}
			}
			if((map_c - (map_c / 10 * 10) == 4))
			{
				if((dash_c == 0) || (dash_c == 3))
				{
					if(scr_c == 0)
					{
						SprShow(lpsprStar,GRA_ON);
						graph_shownum(lpsprStar);
					}
					string_c = key_main(lpsprPl, map_c);
				}
				if((string_c == 106) && (dash_c == 0))
				{
					SprShow(lpsprStar,GRA_OFF);
					SprShow(lpsprMn_down,GRA_ON);
					dash_c = 1;
					menue_c = 0;
				}
				else if((string_c == 107) && (dash_c == 3))
				{
					SprShow(lpsprStar,GRA_OFF);
					SprShow(lpsprMn_down,GRA_ON);
					dash_c = 4;
					menue_c = 0;
				}
				if(((string_c == 106) || (string_c == 107)) && (CheckHitKeyAll() != 0) && (menue_c >= 19) && ((dash_c == 1) || (dash_c == 4)))
				{
					SprShow(lpsprMn_down,GRA_OFF);
					menue_c = 0;
					string_c = 0;
					
				}
			}
			if((map_c - (map_c / 10 * 10))  == 2)
			{
				dash_c = gate_main(lpsprGate,dash_c,lpsprPl,player,Key,map_c);
			}
			
		}
		
		else if(game_c == 5)
		{
			if(bap_c >= 1)
			{
				Baphomet_main();
			}
		}
		//	メニュー画面
		else if(game_c	==	10)
		{
			SprShow(lpsprMn,GRA_ON);
			SprShow(lpsprMn_down,GRA_ON);
			SprShow(lpsprYa,GRA_ON);
			SprSetPos(lpsprYa,ya_x,ya_y);
			game_c = 11;
		}
		else if(game_c == 11)
		{
			menue_main(lpsprMn,lpsprYa,lpsprYa2,lpsprWi,player);
			if(player.hp	<=	0)
			{
				game_c	=	0;
			}
		}

		if(game_c == 7)
		{
			if(st_c >= 10)
			{
				game_c = 3;
				enemy_init(lpsprEn,game_c,map_c);
				SprShow(lpsprBlk,GRA_OFF);
			}
		}


		//	ゲームエンド
		if(game_c	==	4)
		{
			StopMusic();
			game_end();
			break;
		}

		//	ゲームクリア
		if(game_c == 8)
		{
			string_c = prologue();
			SprShow(lpsprMn_down,GRA_ON);
			for(i = 0;i < enemy_h;i++)
			{
				for(e = 0;e < enemy_w;e++)
				{
					SprShow(lpsprEn[i][e],GRA_OFF);
				}
			}
			SprShow(lpsprGate,GRA_OFF);
			SprShow(lpsprPl,GRA_OFF);
			if(string_c == 208)
			{
				PlayMusic("sound/game_sound.MP3",DX_PLAYTYPE_LOOP);
				SetVolumeMusic(1);
			}
			if(string_c == 0)
			{
				StopMusic();
				SprShow(lpsprMn_down,GRA_OFF);
				game_c = 0;
			}
		}
		if((scr_c == 0) && (game_c != 7))
		{
			atari_wall(lpsprPl,player,map_c);
		}

		st_c++;
		menue_c++;
		if(((dash_c == 2) || (dash_c == 5)) && (lpsprGate->show_num < 55))
		{
			graph_shownum(lpsprGate);
		}
		if((game_c == 3) || (game_c == 5)|| (game_c == 10) || (game_c == 11))
		{
			MapMain(map_c,scroll,lpsprBap);
			if((lpsprGate->g_show != GRA_ON) || (lpsprBap->g_show != GRA_ON))
			{
				if(((map_c == 2) || (map_c == 12)) && (scr_c == 0))
				{
					SprShow(lpsprGate,GRA_ON);
					if(map_c == 12)
					{
						SprShow(lpsprBap,GRA_ON);
					}
				}
			}
		}
		if((game_c != 3) || (game_c != 5)|| (game_c != 10) || (game_c != 11))
		{
			if(map_c != 12)
			{
				SprShow(lpsprBap,GRA_OFF);
			}
			if((map_c != 2) && (map_c != 12))
			{
				SprShow(lpsprGate,GRA_OFF);
			}
		}
		
		SprDraw();
		String_Draw(player,string_c);

		//fps調整
		FPS::getInstance()->update();
	}

	// instanceの削除
	FPS::deleteInstance();
	
	return	0;

}

int game_init()
{
	
	
	scr_c			=	0;
	koshika			=	0;
	game_c			=	0;
	menue_c			=	0;
	menue_koshika	=	0;
	map_c			=	0;
	scroll			=	0;
	string_c		=	0;
	allnum			=	1;
	xnum			=	1;
	ynum			=	1;
	//-------------------------------------------------------------------------------------
	//		敵能力初期設定
	//		2013/01/21
	//-------------------------------------------------------------------------------------
	allnum	= 4;
	xnum	= 4;
	for(i = 0;i < enemy_h;i++)
	{
		for(e = 0;e < enemy_w;e++)
		{
			graph_h = maptip_size;
			graph_w = maptip_size;
			lpsprEn[i][e] = spr_create("graphic/enemy.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
			if(lpsprEn[i][e]	==	NULL)
			{
				return	(-1);
			}
			lpsprEn[i][e]->h	=	maptip_size;
			lpsprEn[i][e]->w	=	maptip_size;
			SprSetDepth(lpsprEn[i][e],52000);
			SprShow(lpsprEn[i][e],GRA_OFF);
		}
	}
	
	allnum	= 1;
	xnum	= 1;
	

	graph_h = WINDOW_SIZE_H;
	graph_w = WINDOW_SIZE_W;
	lpsprTi = spr_create("graphic/title.PNG" , TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprTi == NULL)
	{
		return (-1);
	}
	SprSetPos(lpsprTi,0,0);
	SprSetDepth(lpsprTi,50000);

	lpsprBlk = spr_create("graphic/black.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprBlk == NULL)
	{
		return (-1);
	}
	SprSetPos(lpsprBlk,0,0);
	SprSetDepth(lpsprBlk,1000);

	lpsprend = spr_create("graphic/prologue_end.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprend == NULL)
	{
		return (-1);
	}
	SprSetPos(lpsprend,0,0);
	SprSetDepth(lpsprend,50000);

	
	allnum	= 4;
	xnum	= 4;
	graph_h = maptip_size*6;
	graph_w = maptip_size*4;
	lpsprGate = spr_create("graphic/hellgate.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprGate == NULL)
	{
		return (-1);
	}
	SprSetPos(lpsprGate,((WINDOW_SIZE_W / 2)-(graph_w / 2)),0);
	SprSetDepth(lpsprGate,51000);
	SprShow(lpsprGate,GRA_OFF);


	graph_h = maptip_size;
	graph_w = maptip_size;
	lpsprStar = spr_create("graphic/star.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprStar == NULL)
	{
		return (-1);
	}
	SprSetDepth(lpsprStar,50000);
	SprSetPos(lpsprStar,650,510);
	SprShow(lpsprStar,GRA_OFF);
	
	lpsprPl	=	spr_create("graphic/player.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprPl	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprPl,((WINDOW_SIZE_W - maptip_size) / 2),(WINDOW_SIZE_H - (map_waku_y + maptip_size)));
	SprSetDepth(lpsprPl,50000);
	SprShow(lpsprPl,GRA_OFF);

	lpsprBap	=	spr_create("graphic/baphomet.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprBap	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprBap,((5 * maptip_size) + map_waku_x),((2 * maptip_size) + map_waku_y));
	SprSetDepth(lpsprBap,50000);
	SprShow(lpsprBap,GRA_OFF);

	allnum	= 1;
	xnum	= 1;


	graph_h = 150;
	graph_w = 250;
	lpsprMn	=	spr_create("graphic/menue_top.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprMn	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprMn,Witop_x,0);
	SprSetDepth(lpsprMn,30000);
	SprShow(lpsprMn,GRA_OFF);

	graph_h = 300;
	graph_w = 250;
	lpsprMn_up	=	spr_create("graphic/menue_big_window.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprMn_up	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprMn_up,0,50);
	SprSetDepth(lpsprMn_down,30000);
	SprShow(lpsprMn_up,GRA_OFF);

	graph_h	= 200;
	graph_w	= 800;
	lpsprMn_down	=	spr_create("graphic/menue_down.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprMn_down	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprMn_down,0,Widown_y);
	SprSetDepth(lpsprMn_down,30000);
	SprShow(lpsprMn_down,GRA_OFF);

	graph_h	= graph_w	= 24;
	
	
	lpsprYa	=	spr_create("graphic/menue_ya.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprYa	==	NULL)
	{
		return	(-1);
	}
	SprSetDepth(lpsprYa,27000);

	graph_h	= graph_w	= 24;
	lpsprYa2	=	spr_create("graphic/menue_ya.PNG",	TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprYa2	==	NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprYa2,ya2_x,ya2_y);
	SprSetDepth(lpsprYa2,27000);
	SprShow(lpsprYa2,GRA_OFF);

	graph_h	= 100;
	graph_w	= 150;
	lpsprWi		=	spr_create("graphic/menue_window.PNG",TRUE,graph_h,graph_w,allnum,xnum,ynum);
	if(lpsprWi == NULL)
	{
		return	(-1);
	}
	SprSetPos(lpsprWi,Wi_x,Wi_y);
	SprSetDepth(lpsprWi,28000);
	SprShow(lpsprWi,GRA_OFF);

	return 0;
}

//==================================================================================
//		プロローグ
//==================================================================================
int		prologue()
{
	string_c += (st_c / 75);
	if(st_c >= 75)
	{
		st_c = 0;
	}
	if(string_c == 27)
	{
		string_c = 0;
	}
	if(string_c == 218)
	{
		string_c = 0;
	}
	return string_c;
}

void	player_hantei()
{
	//移動範囲制限map0のみ//出口
	if((lpsprPl->y + lpsprPl->h) >= (maptip_size * 18 + 12))
	{
		if((map_c - (map_c /10 *10) == 2) && (dash_c <= 1))
		{		
			lpsprPl->y	=	(maptip_size * 18 + 12 - lpsprPl->h);
		}
	}
	//=======================================================
	//		キャラスクロール
	//		2012/11/20_home	H.tanaka
	//=======================================================
	//	上端
	if((scr_c	==	0)	&&	(lpsprPl->y	<=	(0 + map_waku_y)))
	{
		if(dash_c == 2)
		{
			dash_c = 3;
			map_c  = 12;
			st_c = 0;
			SprSetPos(lpsprStar,620,130);
			lpsprPl->y = WINDOW_SIZE_H - (map_waku_y + lpsprPl->h);
			lpsprGate->show_num = 0;
			SprShow(lpsprBlk,GRA_ON);
			game_c = 7;
		}
		if(dash_c == 5)
		{
			StopMusic();
			string_c = 200;
			SprShow(lpsprBap,GRA_OFF);
			game_c = 8;
			dash_c = 0;
			st_c = 0;
		}
	}
	//	下端
	else if((scr_c	==	0)	&&	((lpsprPl->y + lpsprPl->h)	>	(WINDOW_SIZE_H - map_waku_y)))
	{
		//クリア時
		/*
		StopMusic();
		string_c = 200;
		game_c = 8;
		dash_c = 0;
		st_c = 0;
		*/
		//map_c -= 10;
	}
	//	右端
	else if((scr_c	==	0)	&&	((lpsprPl->x + lpsprPl->w)	>	(WINDOW_SIZE_W - map_waku_x)))
	{
		scr_c	=	3;
		scroll	=	3;
		map_c++;
	}
	//	左端
	else if((scr_c	==	0)	&&	(lpsprPl->x	<	(0 + map_waku_x)))
	{
		scr_c	=	4;
		scroll	=	4;
		map_c--;
	}

}

void	player_scroll(void)
{
	if(scr_c	==	3)
	{
		

		if(koshika != 1)
		{
			if(lpsprPl->x	>	0)
			{
				SprMove(lpsprPl,-player_speed,0);
			}
			else //if(lpsprPl->x	<=	0)
			{
				koshika	=	1;
			}
		}
		else
		{
			if(lpsprPl->x < map_waku_x)
			{
				SprMove(lpsprPl,2,0);
			}
			else
			{
				scr_c	=	0;
				koshika	=	0;
			}
		}
	}
	else if(scr_c	==	4)
	{
		
		if(koshika != 1)
		{
			if((lpsprPl->x + lpsprPl->w)	<	WINDOW_SIZE_W)
			{
				SprMove(lpsprPl,player_speed,0);
			}
			else //if((lpsprPl->x + lpsprPl->w)	>=	WINDOW_SIZE_W)
			{
				koshika	=	1;
			}
		}
		else
		{
			if(lpsprPl->x	>	WINDOW_SIZE_W - (map_waku_x + maptip_size))
			{
				SprMove(lpsprPl,-2,0);
			}
			else
			{
				scr_c	=	0;
				koshika	=	0;
			}
		}
	}
}

//==================================================================================
//		メニュー画面
//		制作年月日					制作者
//		2013/01/20					H.tanaka
//==================================================================================
int	menue_main(ADV_MAIN	*lpsprMn,ADV_MAIN	*lpsprYa,ADV_MAIN	*lpsprYa2,ADV_MAIN	*lpsprWi,CHARA_MAIN	player)
{
	//メニュー画面初期
	if(menue_koshika	==	0)
	{
		string_c = 100;
		//アイコンの移動
		if(Key[KEY_INPUT_UP]	!=	0)
		{
			if(lpsprYa->y	!=	ya_y)
			{
				lpsprYa->y	-=	78;
			}
			else
			{
				//音を鳴らす
			}
		}
		else if(Key[KEY_INPUT_DOWN]	!=	0)
		{
			if(lpsprYa->y	!=	(ya_y + 78))
			{
				lpsprYa->y	+=	78;
			}
			else
			{
				//音を鳴らす
			}
		}
		else if(Key[KEY_INPUT_RIGHT]	!=	0)
		{
			if(lpsprYa->x	!=	(ya_x + 100))
			{
				lpsprYa->x	+=	100;
			}
			else
			{
				//音を鳴らす
			}
		}
		else if(Key[KEY_INPUT_LEFT]	!=	0)
		{
			if(lpsprYa->x	!=	ya_x)
			{
				lpsprYa->x	-=	100;
			}
			else
			{
				//音を鳴らす
			}
		}

		
		
		//メニュー決定
		if((Key[KEY_INPUT_Z]	!=	0)	&&	(menue_c	>	19))
		{
			SprShow(lpsprYa2,GRA_ON);
			menue_c	=	0;
			if((lpsprYa->x	==	ya_x)	&&	(lpsprYa->y	==	ya_y))
			{
				//装備
				string_c = 0;
				menue_koshika	=	1;
			}
			else if((lpsprYa->x	==	ya_x)	&&	(lpsprYa->y	==	(ya_y + 78)))
			{
				//アイテム
				string_c = 0;
				menue_koshika	=	2;
			}
			else if((lpsprYa->x	==	(ya_x + 100))	&&	(lpsprYa->y	==	ya_y))
			{
				//セーブ
				string_c = 102;
				menue_koshika	=	3;
				lpsprYa2->y = (ya2_y + 24);
			}
			else if((lpsprYa->x	==	(ya_x + 100))	&&	(lpsprYa->y	==	(ya_y + 78)))
			{
				//ゲーム終了
				string_c = 101;
				menue_koshika	=	4;
				SprShow(lpsprWi,GRA_ON);
				lpsprYa2->x	= Wi_x + 30;
				lpsprYa2->y	= Wi_y + 20;
			}
		}

		

		//メニュー終了
		if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
		{
			SprShow(lpsprMn,GRA_OFF);
			SprShow(lpsprMn_down,GRA_OFF);
			SprShow(lpsprYa,GRA_OFF);
			lpsprYa->x	=	ya_x;
			lpsprYa->y	=	ya_y;
			string_c = 0;
			game_c	=	3;
			menue_c	=	0;
		}
	}
	//装備
	else if(menue_koshika	==	1)
	{
		if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
		{
			menue_koshika = 0;
			SprShow(lpsprYa2,GRA_OFF);
			lpsprYa2->x	= ya2_x;
			lpsprYa2->y = ya2_y;
			menue_c = 0;
		}
	}
	//アイテム
	else if(menue_koshika	==	2)
	{
		if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
		{
			menue_koshika = 0;
			SprShow(lpsprYa2,GRA_OFF);
			lpsprYa2->x	= ya2_x;
			lpsprYa2->y = ya2_y;
			menue_c = 0;
		}
	}
	//セーブ
	else if(menue_koshika	==	3)
	{
		if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
		{
			menue_koshika = 0;
			SprShow(lpsprYa2,GRA_OFF);
			lpsprYa2->x	= ya2_x;
			lpsprYa2->y = ya2_y;
			menue_c = 0;
		}
	}
	//終了
	else if(menue_koshika	==	4)
	{
		if(Key[KEY_INPUT_UP]	!=	0)
		{
			if(lpsprYa2->y	!=	(Wi_y + 20))
			{
				lpsprYa2->y	-=	40;
			}
		}
		else if(Key[KEY_INPUT_DOWN]	!=	0)
		{
			if(lpsprYa2->y	!=	(Wi_y + 60))
			{
				lpsprYa2->y	+=	40;
			}
		}
		if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
		{
			menue_koshika = 0;
			SprShow(lpsprYa2,GRA_OFF);
			SprShow(lpsprWi,GRA_OFF);
			lpsprYa2->x	= ya2_x;
			lpsprYa2->y = ya2_y;
			menue_c = 0;
		}
		else if((Key[KEY_INPUT_Z]	!=	0)	&&	(menue_c	>	19))
		{
			if(lpsprYa2->y	!=	(Wi_y + 20))
			{
				menue_koshika = 0;
				SprShow(lpsprYa2,GRA_OFF);
				SprShow(lpsprWi,GRA_OFF);
				lpsprYa2->x	= ya2_x;
				lpsprYa2->y = ya2_y;
				menue_c = 0;
			}
			else
			{
				SprFinish();
				StopMusic();
				game_c = 0;
			}
		}
		
	}
	return string_c;
}

int	title()
{
	if((Key[KEY_INPUT_UP]	!=	0)	&&	(menue_c >= 19))
	{
		if(lpsprYa->y	!=	330)
		{
			lpsprYa->y	-=	55;
			menue_c = 0;
		}
	}
	else if((Key[KEY_INPUT_DOWN]	!=	0)	&&	(menue_c >= 19))
	{
		if(lpsprYa->y	!=	(330 + (55*2)))
		{
			lpsprYa->y	+=	55;
			menue_c = 0;
		}
	}

	//メニュー決定
	if((Key[KEY_INPUT_Z]	!=	0)	&&	(menue_c >= 19))
	{
		menue_c	=	0;
		if(lpsprYa->y	==	330)
		{
			//はじめから
			return 2;
		}
		else if(lpsprYa->y	==	(330 + 55))
		{
			//つづきから
			//セーブデータのロード
			return 2;
		}
		else if(lpsprYa->y	==	(330 + (55 * 2)))
		{
			//ゲーム終了
			return 4;
		}
	}
	return 1;
}

void	Baphomet_main()
{
	if(Key[KEY_INPUT_UP]	!=	0)
	{
		if(lpsprYa2->y	!=	(Wi_y + 20))
		{
			lpsprYa2->y	-=	40;
		}
		menue_c = 0;

	}
	else if(Key[KEY_INPUT_DOWN]	!=	0)
	{
		if(lpsprYa2->y	!=	(Wi_y + 60))
		{
			lpsprYa2->y	+=	40;
		}
		menue_c = 0;
	}

	if((Key[KEY_INPUT_Z]	!=	0)	&&	(menue_c	>	19))
	{
		menue_c = 0;
		string_c = 0;
		//回復
		if(lpsprYa2->y == (Wi_y + 20))
		{
			bap_c = 2;
			SprShow(lpsprMn_down,GRA_OFF);
		}
		//アイテム
		else if(lpsprYa2->y == (Wi_y + 60))
		{
			//bap_c = 3;
			//SprShow(lpsprMn_up,GRA_ON);
		}
	}
	else if((Key[KEY_INPUT_X]	!=	0)	&&	(menue_c	>	19))
	{
		SprShow(lpsprMn_down,GRA_OFF);	
		bap_c = 0;
		menue_c = 0;
		game_c = 3;
		string_c = 0;
	}
	if(bap_c != 1)
	{
		SprShow(lpsprWi,GRA_OFF);
		SprShow(lpsprYa2,GRA_OFF);
	}
	
	if(bap_c == 2)
	{
		if(player.hp == player.max_hp)
		{
			SprShow(lpsprMn_down,GRA_ON);
			string_c = 104;
			if((CheckHitKeyAll() != 0) && (menue_c >= 19))
			{
				SprShow(lpsprMn_down,GRA_OFF);
				SprShow(lpsprWi,GRA_OFF);
				SprShow(lpsprYa2,GRA_OFF);
				bap_c = 0;
				menue_c = 0;
				game_c = 3;
				string_c = 0;
			}
		}
		else
		{
			player.hp = Baphomet_hp(lpsprBap,player);
		}
	}
	/*else if(bap_c == 3)
	{
		SprShow(lpsprMn_down,GRA_ON);
		string_c = Baphomet_item();
		if((CheckHitKeyAll() != 0) && (menue_c >= 19))
		{
			SprShow(lpsprMn_down,GRA_OFF);
			SprShow(lpsprMn_up,GRA_OFF);
			menue_c = 0;
			bap_c = 0;
		}
	}*/
	if(bap_c == 0)
	{
		string_c = 0;
		SprShow(lpsprMn_down,GRA_OFF);
		SprShow(lpsprMn_up,GRA_OFF);
	}
}



void	game_end()
{
	//	描画管理モジュール・終了
	SprFinish();
	//	DXライブラリ・終了
	DxLib_End();
}

#include	"frameWork/hellsgate.h"

int move_c;
int l;
int o;
int greatkoshika;
CHARA_MAIN	enemy[enemy_h][enemy_w];

int enemy_hani;
int enemy_s;
//===================================================
//	ä÷êîåƒÇ—èoÇµ
//===================================================
int		enemy_move(ADV_MAIN *lpsprPl,ADV_MAIN *lpsprEn,CHARA_MAIN player,CHARA_MAIN enemy,int greatkoshika,ADV_MAIN *lpsprGate);

//==================================================================================
//		ìGìÆÇ´
//		êßçÏîNåéì˙					êßçÏé“
//		2013/01/21					H.tanaka
//==================================================================================
int		enemy_main(ADV_MAIN	*lpsprEn[enemy_h][enemy_w],ADV_MAIN *lpsprPl,CHARA_MAIN player,int map_c,int dash_c,ADV_MAIN *lpsprGate)
{
	if((dash_c == 1) || (dash_c == 4))
	{
		enemy_hani  = 150;
		enemy_s		= 1;
	}
	if(dash_c == 5)
	{
		enemy_hani	= 175;
		enemy_s		= 1;
	}
	else
	{
		enemy_hani	= 100;
		enemy_s		= 1;
	}
	//ìGä÷êî
	for(l = 0;l < enemy_h;l++)
	{
		for(o = 0;o < enemy_w;o++)
		{
			if(map_c <= 13)
			{
				if((l >= 2) ||(o >= 2))
				{
					break;
				}
			}
			enemy[l][o].x = lpsprEn[l][o]->x;
			enemy[l][o].y = lpsprEn[l][o]->y;
			if(enemy[l][o].dmg == 0)
			{
				graph_shownum(lpsprEn[l][o]);
				player.hp = enemy_move(lpsprPl,lpsprEn[l][o],player,enemy[l][o],greatkoshika,lpsprGate);
				if(lpsprEn[l][o]->dmg != 0)
				{
					enemy[l][o].dmg++;
					greatkoshika++;
				}
			}
			else if((lpsprEn[l][o]->dmg == 1) && (enemy[l][o].dmg < 7))
			{
				enemy[l][o].dmg++;
				if(greatkoshika == 0)
				{
					sayenemy(lpsprEn[l][o],lpsprPl,enemy[l][o]);
				}
				atari_wall(lpsprPl,player,map_c);
				//ìGÇ©ÇÁó£ÇÍÇƒÇ¢Ç≠ä÷êî
				if((lpsprPl->x < (lpsprEn[l][o]->x + lpsprEn[l][o]->w)) && 
					((lpsprPl->x + lpsprPl->w) > lpsprEn[l][o]->x))
				{
					if((lpsprPl->y < (lpsprEn[l][o]->y + lpsprEn[l][o]->h)) && 
					((lpsprPl->y + lpsprPl->h) > lpsprEn[l][o]->y))
					{
						if(lpsprPl->x > 400)
						{
							SprMove(lpsprPl,-kobuta,0);
						}
						else
						{
							SprMove(lpsprPl,kobuta,0);
						}
						if(lpsprPl->y > 300)
						{
							SprMove(lpsprPl,0,-kobuta);
						}
						else
						{
							SprMove(lpsprPl,0,kobuta);
						}
					}
				}
			}
			if(enemy[l][o].dmg >= 6)
			{
				lpsprEn[l][o]->dmg = 0;
				enemy[l][o].dmg = 0;
			}
			
			if(greatkoshika != 0)
			{
				greatkoshika++;
			}
			if(greatkoshika >= 150)
			{
				greatkoshika = 0;
				LoadDivGraph("graphic/player.PNG",lpsprPl->allnum,lpsprPl->x_num,lpsprPl->y_num,lpsprPl->w,lpsprPl->h,lpsprPl->sprNo);
			}

			
			
			atari_wall(lpsprEn[l][o],enemy[l][o],map_c);
			
			//enemy[l][o].hp = damage_trap_enemy(lpsprEn[l][o],enemy[l][o],map_c);
			if(enemy[l][o].hp <= 0)
			{
				SprShow(lpsprEn[l][o],GRA_OFF);
			}
		}
	}
	return player.hp;
}


int		enemy_move(ADV_MAIN *lpsprPl,ADV_MAIN *lpsprEn,CHARA_MAIN player,CHARA_MAIN enemy,int greatkoshika,ADV_MAIN *lpsprGate)
{
	if(lpsprEn->g_show != GRA_OFF)
	{
		if((lpsprPl->x > lpsprEn->x - enemy_hani) && (lpsprPl->x < lpsprEn->x + enemy_hani))
		{
			if((lpsprPl->y > lpsprEn->y - enemy_hani) && (lpsprPl->y < lpsprEn->y + enemy_hani))
			{
				enemy.move_c = 1;
				if((lpsprPl->x < lpsprEn->x + maptip_size - 7) && (lpsprPl->x > lpsprEn->x - maptip_size + 7))
				{
					if((lpsprPl->y < lpsprEn->y + maptip_size) && (lpsprPl->y > lpsprEn->y - maptip_size))
					{
						if((lpsprEn->dmg == 0) && (greatkoshika == 0))
						{
							player.hp -= enemy_atp;
							LoadDivGraph("graphic/player_dmg.PNG",lpsprPl->allnum,lpsprPl->x_num,lpsprPl->y_num,lpsprPl->w,lpsprPl->h,lpsprPl->sprNo);
							lpsprEn->dmg = 1;
						}
					}
				}
				if(lpsprEn->dmg != 1)
				{
					if((lpsprEn->x > (lpsprGate->x + lpsprGate->w)) || (lpsprEn->x < (lpsprGate->x - lpsprEn->w)) || (lpsprEn->y > (lpsprGate->y + lpsprGate->h)) || (lpsprGate->show_num != 0) || (lpsprGate->g_show != GRA_ON))
					{
						if(lpsprPl->x < lpsprEn->x)
						{
							SprMove(lpsprEn,-enemy_s,0);
							LoadDivGraph("graphic/enemy.PNG",lpsprEn->allnum,lpsprEn->x_num,lpsprEn->y_num,lpsprEn->w,lpsprEn->h,lpsprEn->sprNo);
						}
						else if(lpsprPl->x > lpsprEn->x)
						{
							SprMove(lpsprEn,enemy_s,0);
							LoadDivGraph("graphic/enemy_right.PNG",lpsprEn->allnum,lpsprEn->x_num,lpsprEn->y_num,lpsprEn->w,lpsprEn->h,lpsprEn->sprNo);
						}

						if(lpsprPl->y < lpsprEn->y)
						{
							SprMove(lpsprEn,0,-enemy_s);
						}
						else if(lpsprPl->y > lpsprEn->y)
						{
							SprMove(lpsprEn,0,enemy_s);
						}
					}
				}
			}
			else
			{
				enemy.move_c = 0;
			}
		}
		else
		{
			enemy.move_c = 0;
		}
	}
	return player.hp;
}

void	sayenemy(ADV_MAIN *lpsprEn,ADV_MAIN *lpsprPl,CHARA_MAIN enemy)
{
	//É_ÉÅÅ[ÉWãÚÇÁÇ¢éûÇÃé©ã@à⁄ìÆ
	if(lpsprPl->x < lpsprEn->x)
	{
		SprMove(lpsprPl,-kobuta,0);
	}
	else if(lpsprPl->x > lpsprEn->x)
	{
		SprMove(lpsprPl,kobuta,0);
	}

	if(lpsprPl->y < lpsprEn->y)
	{
		SprMove(lpsprPl,0,-kobuta);
	}
	else if(lpsprPl->y > lpsprEn->y)
	{
		SprMove(lpsprPl,0,kobuta);
	}
}

void	enemy_init(ADV_MAIN *lpspr[enemy_h][enemy_w],int game_c,int map_c)
{
	
	if(game_c == 2)
	{
		move_c = 0;
		greatkoshika = 0;
		enemy_hani = 0;
		enemy_s = 0;
		SprSetPos(lpspr[0][0],600,200);
		SprSetPos(lpspr[0][1],600,400);
		SprSetPos(lpspr[1][0],200,200);
		SprSetPos(lpspr[1][1],200,400);
		for(l = 0;l < enemy_h;l++)
		{
			for(o = 0;o < enemy_w;o++)
			{
				SprShow(lpspr[l][o],GRA_ON);
				lpspr[l][o]->dmg	= 0;
				enemy[l][o].move_c  = 0;
				enemy[l][o].dmg	    = 0;
				enemy[l][o].atp		=	enemy_atp;
				enemy[l][o].blp		=	enemy_blp;
				enemy[l][o].max_hp	=	enemy_hp;
				enemy[l][o].hp		=	enemy_hp;
			}
		}
	}
	else if(game_c == 3)
	{
		for(l = 0;l < enemy_h;l++)
		{
			for(o = 0;o < enemy_w;o++)
			{
				SprShow(lpspr[l][o],GRA_OFF);
			}
		}
		if(map_c == 2)
		{
			SprSetPos(lpspr[0][0],600,200);
			SprSetPos(lpspr[0][1],600,400);
			SprSetPos(lpspr[1][0],200,200);
			SprSetPos(lpspr[1][1],200,400);
		}
		else if(map_c == 3)
		{
			SprSetPos(lpspr[0][0],600,150);
			SprSetPos(lpspr[0][1],500,300);
			SprSetPos(lpspr[1][0],200,150);
			SprSetPos(lpspr[1][1],200,300);
		}
		else if(map_c == 4)
		{
			SprSetPos(lpspr[0][0],500,150);
			SprSetPos(lpspr[0][1],500,250);
			SprSetPos(lpspr[1][0],200,200);
			SprSetPos(lpspr[1][1],200,400);
		}
		else if(map_c == 12)
		{
			SprSetPos(lpspr[0][0],384,100);
			SprSetPos(lpspr[0][1],500,200);
			SprSetPos(lpspr[1][0],500,300);
			SprSetPos(lpspr[1][1],420,400);
		}
		else if(map_c == 13)
		{
			SprSetPos(lpspr[0][0],100,192);
			SprSetPos(lpspr[0][1],250,200);
			SprSetPos(lpspr[1][0],450,300);
			SprSetPos(lpspr[1][1],650,350);
		}
		else if(map_c == 14)
		{
			SprSetPos(lpspr[0][0],200,200);
			SprSetPos(lpspr[0][1],200,400);
			SprSetPos(lpspr[1][0],640,200);
			SprSetPos(lpspr[1][1],700,200);
		}
	}
}

void	enemy_seigyo(ADV_MAIN *lpsprEn[enemy_h][enemy_w])
{
	for(l = 0;l < enemy_h;l++)
	{
		for(o = 0;o < enemy_w;o++)
		{
			//ìGã@ìØémÇ™Ç‘Ç¬Ç©ÇÁÇ»Ç¢ÇÊÇ§Ç…Ç∑ÇÈ
			//[0][1]
			if(((l != 0) || (o != 1)) && (lpsprEn[0][1]->g_show == GRA_ON))
			{
				if((lpsprEn[l][o]->x > lpsprEn[0][1]->x - enemy_koshika) && (lpsprEn[l][o]->x < lpsprEn[0][1]->x + enemy_koshika))
				{
					if((lpsprEn[l][o]->y > lpsprEn[0][1]->y - enemy_koshika) && (lpsprEn[l][o]->y < lpsprEn[0][1]->y + enemy_koshika))
					{
						if(lpsprEn[l][o]->x < lpsprEn[0][1]->x)
						{
							SprMove(lpsprEn[0][1],2,0);
							LoadDivGraph("graphic/enemy.PNG",lpsprEn[0][1]->allnum,lpsprEn[0][1]->x_num,lpsprEn[0][1]->y_num,lpsprEn[0][1]->w,lpsprEn[0][1]->h,lpsprEn[0][1]->sprNo);
						}
						else if(lpsprEn[l][o]->x > lpsprEn[0][1]->x)
						{
							SprMove(lpsprEn[0][1],-2,0);
							LoadDivGraph("graphic/enemy_right.PNG",lpsprEn[0][1]->allnum,lpsprEn[0][1]->x_num,lpsprEn[0][1]->y_num,lpsprEn[0][1]->w,lpsprEn[0][1]->h,lpsprEn[0][1]->sprNo);
						}

						if(lpsprEn[l][o]->y < lpsprEn[0][1]->y)
						{
							SprMove(lpsprEn[0][1],0,2);
						}
						else if(lpsprEn[l][o]->y > lpsprEn[0][1]->y)
						{
							SprMove(lpsprEn[0][1],0,-2);
						}
					}
				}
			}

			//[1][0]
			if(((l != 1) || (o != 0)) && (lpsprEn[1][0]->g_show == GRA_ON))
			{
				if((lpsprEn[l][o]->x > lpsprEn[1][0]->x - enemy_koshika) && (lpsprEn[l][o]->x < lpsprEn[1][0]->x + enemy_koshika))
				{
					if((lpsprEn[l][o]->y > lpsprEn[1][0]->y - enemy_koshika) && (lpsprEn[l][o]->y < lpsprEn[1][0]->y + enemy_koshika))
					{
						if(lpsprEn[l][o]->x < lpsprEn[1][0]->x)
						{
							SprMove(lpsprEn[1][0],1,0);
							LoadDivGraph("graphic/enemy.PNG",lpsprEn[1][0]->allnum,lpsprEn[1][0]->x_num,lpsprEn[1][0]->y_num,lpsprEn[1][0]->w,lpsprEn[1][0]->h,lpsprEn[1][0]->sprNo);
						}
						else if(lpsprEn[l][o]->x > lpsprEn[1][0]->x)
						{
							SprMove(lpsprEn[1][0],-1,0);
							LoadDivGraph("graphic/enemy_right.PNG",lpsprEn[1][0]->allnum,lpsprEn[1][0]->x_num,lpsprEn[1][0]->y_num,lpsprEn[1][0]->w,lpsprEn[1][0]->h,lpsprEn[1][0]->sprNo);
						}

						if(lpsprEn[l][o]->y < lpsprEn[1][0]->y)
						{
							SprMove(lpsprEn[1][0],0,1);
						}
						else if(lpsprEn[l][o]->y > lpsprEn[1][0]->y)
						{
							SprMove(lpsprEn[1][0],0,-1);
						}
					}
				}
			}
			//[1][1]
			if(((l != 1) || (o != 1)) && (lpsprEn[1][1]->g_show == GRA_ON))
			{
				if((lpsprEn[l][o]->x > lpsprEn[1][1]->x - enemy_koshika) && (lpsprEn[l][o]->x < lpsprEn[1][1]->x + enemy_koshika))
				{
					if((lpsprEn[l][o]->y > lpsprEn[1][1]->y - enemy_koshika) && (lpsprEn[l][o]->y < lpsprEn[1][1]->y + enemy_koshika))
					{
						if(lpsprEn[l][o]->x < lpsprEn[1][1]->x)
						{
							SprMove(lpsprEn[1][1],1,0);
							LoadDivGraph("graphic/enemy.PNG",lpsprEn[1][1]->allnum,lpsprEn[1][1]->x_num,lpsprEn[1][1]->y_num,lpsprEn[1][1]->w,lpsprEn[1][1]->h,lpsprEn[1][1]->sprNo);
						}
						else if(lpsprEn[l][o]->x > lpsprEn[1][1]->x)
						{
							SprMove(lpsprEn[1][1],-1,0);
							LoadDivGraph("graphic/enemy_right.PNG",lpsprEn[1][1]->allnum,lpsprEn[1][1]->x_num,lpsprEn[1][1]->y_num,lpsprEn[1][1]->w,lpsprEn[1][1]->h,lpsprEn[1][1]->sprNo);
						}

						if(lpsprEn[l][o]->y < lpsprEn[1][1]->y)
						{
							SprMove(lpsprEn[1][1],0,1);
						}
						else if(lpsprEn[l][o]->y > lpsprEn[1][1]->y)
						{
							SprMove(lpsprEn[1][1],0,-1);
						}
					}
				}
			}
		}
	}
}
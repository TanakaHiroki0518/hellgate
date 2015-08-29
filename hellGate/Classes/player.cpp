#include	<DxLib.h>
#include	"frameWork/hellsgate.h"



//==================================================================================
//		自機移動
//		更新年月日					制作者
//		2013/01/20					H.tanaka
//==================================================================================
int	player_move(ADV_MAIN	*lpsprPl,CHARA_MAIN	player,char Key[256])
{
	
	////////////////////////////////////////////////////////////////////////////////////
	//		ゲームメイン
	//		更新年月日					製作者
	//		2012/12/18					H.tanaka
	////////////////////////////////////////////////////////////////////////////////////
	
	if(Key[KEY_INPUT_UP]	!=	0)
	{
		SprMove(lpsprPl,0,-2);
		if(player.move_c - (player.move_c / 10 * 10) == 0)
		{
			player.move_c++;	//	上
		}
		else if(player.move_c - (player.move_c / 10 * 10) >= 2)
		{
			player.move_c--;
		}
	}
	if(Key[KEY_INPUT_DOWN]	!=	0)
	{
		SprMove(lpsprPl,0,2);
		if(player.move_c - (player.move_c / 10 * 10) == 0)
		{
			player.move_c += 2;	//	上
		}
		else if(player.move_c - (player.move_c / 10 * 10) == 1)
		{
			player.move_c++;
		}
	}
	if(Key[KEY_INPUT_RIGHT]	!=	0)
	{
		SprMove(lpsprPl,2,0);
		if(player.move_c < 10)
		{
			player.move_c += 10;
		}
		else if(player.move_c <= 20)
		{
			player.move_c -= 10;
		}
	}
	if(Key[KEY_INPUT_LEFT]	!=	0)
	{
		SprMove(lpsprPl,-2,0);
		if(player.move_c < 20)
		{
			player.move_c += 20;
		}
		else if(player.move_c / 10 == 1)
		{
			player.move_c += 10;
		}
	}
	if((Key[KEY_INPUT_UP]	==	0) && (Key[KEY_INPUT_DOWN]	==	0) && 
		(Key[KEY_INPUT_RIGHT]	==	0) && (Key[KEY_INPUT_LEFT]	==	0))
	{
		player.move_c = 0;
	}
	return player.move_c;
}

//ダメージ床に当たった時の自機移動関数
void	saykim(ADV_MAIN	*lpspr,CHARA_MAIN chara)
{
	if(chara.move_c - (chara.move_c / 10 * 10) == 1)
	{
		SprMove(lpspr,0,3);
	}
	else if(chara.move_c - (chara.move_c / 10 * 10) == 2)
	{
		SprMove(lpspr,0,-3);
	}
	if((chara.move_c >= 10) && (chara.move_c < 20))
	{
		if(chara.move_c == 11)
		{
			SprMove(lpspr,-3,3);
		}
		else if(chara.move_c == 12)
		{
			SprMove(lpspr,-3,-3);
		}
		else
		{
			SprMove(lpspr,-3,0);
		}
	}
	else if(chara.move_c >= 20)
	{
		if(chara.move_c == 21)
		{
			SprMove(lpspr,3,3);
		}
		else if(chara.move_c == 22)
		{
			SprMove(lpspr,3,-3);
		}
		else
		{
			SprMove(lpspr,3,0);
		}
	}
}

int Baphomet_hp(ADV_MAIN *lpsprBap,CHARA_MAIN player)
{
	graph_shownum(lpsprBap);
	if(lpsprBap->show_num == 0)
	{
		player.hp = player.max_hp;
	}
	return player.hp;
}

int	Baphomet_item()
{
	return 105;
}

void	player_bug(ADV_MAIN	*lpspr,CHARA_MAIN player)
{
	if((lpspr->x != player.x) || (lpspr->y != player.y))
	{
		lpspr->x = player.x;
		lpspr->y = player.y;
	}
}
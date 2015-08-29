#include	<stdio.h>
#include	<stdlib.h>
#include	<DxLib.h>
#include	"frameWork/hellsgate.h"

USE_NS_FW

//	描画管理モジュール情報
ADV_MAIN	adv_main[ADV_MAX_MAIN];
//	描画管理モジュール情報（予備）
ADV_MAIN	adv_sub[ADV_MAX_MAIN];

//===========================================================
//		呼び出し用関数宣言
//		制作年/月/日		制作者
//		  2012/10/29		H.tanaka
//===========================================================
//	描画管理モジュール情報初期化
void	InitObject(ADV_MAIN *lpSpr);
//	描画管理モジュール未使用情報取得
ADV_MAIN	*sprGetFreeObject(void);
//	描画管理モジュール確認
long	sprCheckObject(ADV_MAIN *lpSpr);
//	描画オブジェクト並替え
int	sprSort2dObject(const void* lpObj1, const void* lpObj2);




void	game_init()
{
	long	loop;

	for(loop	=	0;loop	<	ADV_MAX_MAIN;loop++)
	{
		InitObject(&adv_main[loop]);
	}

}

//======================================================================
//		描画管理モジュール・終了
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprFinish(void)
{
	long	nLoop;

	//	描画管理モジュール・削除
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		SprDestroy(&adv_main[nLoop]);
	}
}

//======================================================================
//		描画管理モジュール・生成
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
ADV_MAIN *spr_create(const char* lpszName,long nAlpha,int graph_h,int graph_w,int allnum,int xnum,int ynum)
{
	ADV_MAIN *lpSpr;
	
	// ファイル名が空の場合には、nullptrを返す
	if(strcmp(lpszName, "") == 0)
	{
		return	nullptr;
	}

	//	描画管理モジュール未使用情報取得
	lpSpr = sprGetFreeObject();
	if(lpSpr == nullptr)
	{
		return nullptr;
	}
	
	//	DXライブラリ・素材読込
	lpSpr->h = graph_h;
	lpSpr->w = graph_w;
	lpSpr->allnum = allnum;
	lpSpr->x_num = xnum;
	lpSpr->y_num = ynum;
	lpSpr->nAlpha = nAlpha;
	lpSpr->bUsed = 1;

	int nNo[200];
	int	i;
	
	LoadDivGraph(lpszName,lpSpr->allnum,lpSpr->x_num,lpSpr->y_num,lpSpr->w,lpSpr->h,nNo);
	if(lpSpr->allnum != 1)
	{
		for(i = 0;i < lpSpr->allnum;i++)
		{
			if(nNo[i] == -1)
			{
				break;
			}
			lpSpr->sprNo[i] = nNo[i];
		}
	}
	else
	{
		for (i = 0; i < lpSpr->allnum; i++)
		{
			if(nNo[0] == (-1))
			{
				return	nullptr;
			}
			lpSpr->sprNo[i] = nNo[0];
		}
	}

	return	lpSpr;
}

//======================================================================
//		描画管理モジュール・削除
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprDestroy(ADV_MAIN *lpSpr)
{
	long	nResult;
	int i;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	//	DXライブラリ・素材削除
	for(i = 0;i < 4;i++)
	{
		DeleteGraph(lpSpr->sprNo[i]);
	}
	//	描画管理モジュール情報初期化
	InitObject(lpSpr);
}


//======================================================================
//		描画管理モジュール・描画
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprDraw(void)
{
	ADV_MAIN		*lpSpr;
	long			nLoop;

	//	描画オブジェクト並替え
	memset((void*)&adv_sub[0], 0x00, sizeof(ADV_MAIN) * ADV_MAX_MAIN);
	memcpy_s((void*)&adv_sub[0], sizeof(ADV_MAIN) * ADV_MAX_MAIN, (void*)&adv_main[0], sizeof(ADV_MAIN) * ADV_MAX_MAIN);
	qsort((void*)&adv_sub[0], ADV_MAX_MAIN, sizeof(ADV_MAIN), sprSort2dObject);
	
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		lpSpr = &adv_sub[nLoop];
		//	未使用状態の場合
		if(lpSpr->bUsed != 1)
		{
			continue;
		}
		//	非表示状態の場合
		if(lpSpr->g_show != GRA_ON)
		{
			continue;
		}
		//	DXライブラリ・描画
		fw::Draw(lpSpr->x, lpSpr->y, lpSpr->sprNo[(lpSpr->show_num / 14)], lpSpr->nAlpha);
	}
	
}

//======================================================================
//		描画管理モジュール・表示位置設定
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprSetPos(ADV_MAIN *lpSpr, long nX, long nY)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->x = nX;
	lpSpr->y = nY;

}

//======================================================================
//		描画管理モジュール・表示位置取得
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprGetPos(ADV_MAIN *lpSpr, long *lpX, long *lpY)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	if(lpX != NULL)
	{
		*lpX = lpSpr->x;
	}
	if(lpY != NULL)
	{
		*lpY = lpSpr->y;
	}
}

//======================================================================
//		描画管理モジュール・表示奥行き設定
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprSetDepth(ADV_MAIN *lpSpr, long nZ)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->z = nZ;
}

//======================================================================
//		描画管理モジュール・移動
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprMove(ADV_MAIN *lpSpr, long nX, long nY)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->x += nX;
	lpSpr->y += nY;
}

//======================================================================
//		描画管理モジュール・表示切替
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprShow(ADV_MAIN *lpSpr, long nShow)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->g_show = nShow;
}

//======================================================================
//		描画管理モジュール・未使用情報取得
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
ADV_MAIN	*sprGetFreeObject(void)
{
	ADV_MAIN		*lpSpr;
	long			nLoop;

	lpSpr = NULL;
	//	未使用情報検索
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		if(adv_main[nLoop].bUsed == 1)
		{
			continue;
		}
		lpSpr = &adv_main[nLoop];
		break;
	}

	return	lpSpr;
}


//======================================================================
//		描画管理モジュール・初期化
//		制作年/月/日		制作者
//		  2012/10/29		H.tanaka
//======================================================================
void	InitObject(ADV_MAIN *lpSpr)
{
	int i;
	for(i = 0;i < 4;i++)
	{
		lpSpr->sprNo[i]		=	(-1);
	}
	lpSpr->bUsed		=	0;
	lpSpr->x			=	0;
	lpSpr->y			=	0;
	lpSpr->z			=	0;
	lpSpr->h			=	0;
	lpSpr->w			=	0;
	lpSpr->g_show		=	GRA_OFF;
	lpSpr->allnum		=	0;
	lpSpr->x_num		=	0;
	lpSpr->y_num		=	0;
	lpSpr->show_num		=	0;
	lpSpr->dmg			=	0;
}

//======================================================================
//		描画管理モジュール・確認
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
long	sprCheckObject(ADV_MAIN *lpSpr)
{
	long	nResult;
	long	nLoop;

	nResult = 0;
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		//	未使用状態の場合
		if(adv_main[nLoop].bUsed != 1)
		{
			continue;
		}
		//	今回情報とは異なる場所
		if(&adv_main[nLoop] != lpSpr)
		{
			continue;
		}
		//	一致した場所を発見
		nResult = 1;
		break;
	}

	return	nResult;
}

//======================================================================
//		描画オブジェクト並替え
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
int	sprSort2dObject(const void* lpObj1, const void* lpObj2)
{
	ADV_MAIN*	p2dObj1;
	ADV_MAIN*	p2dObj2;

	p2dObj1 = (ADV_MAIN*)lpObj1;
	p2dObj2 = (ADV_MAIN*)lpObj2;

	if(p2dObj1->z > p2dObj2->z)
	{
		return	(-1);
	}
	else if(p2dObj1->z < p2dObj2->z)
	{
		return	1;
	}

	return	0;
}

//======================================================================
//		素材サイズ取得
//		制作年/月/日		制作者
//		  2012/11/20		H.tanaka
//======================================================================
void	SprGetSize(ADV_MAIN *lpSpr, long *lpW, long *lpH)
{
	long	nResult;

	//	描画管理モジュール確認
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	if(lpW != NULL)
	{
		*lpW = lpSpr->w;
	}
	if(lpH != NULL)
	{
		*lpH = lpSpr->h;
	}
}

void	graph_shownum(ADV_MAIN	*lpspr)
{
	if(lpspr->g_show != GRA_OFF)
	{
		lpspr->show_num++;
		if(lpspr->show_num >= 56)
		{
			lpspr->show_num = 0;
		}
	}
}
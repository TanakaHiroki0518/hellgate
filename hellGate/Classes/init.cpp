#include	<stdio.h>
#include	<stdlib.h>
#include	<DxLib.h>
#include	"frameWork/hellsgate.h"

USE_NS_FW

//	�`��Ǘ����W���[�����
ADV_MAIN	adv_main[ADV_MAX_MAIN];
//	�`��Ǘ����W���[�����i�\���j
ADV_MAIN	adv_sub[ADV_MAX_MAIN];

//===========================================================
//		�Ăяo���p�֐��錾
//		����N/��/��		�����
//		  2012/10/29		H.tanaka
//===========================================================
//	�`��Ǘ����W���[����񏉊���
void	InitObject(ADV_MAIN *lpSpr);
//	�`��Ǘ����W���[�����g�p���擾
ADV_MAIN	*sprGetFreeObject(void);
//	�`��Ǘ����W���[���m�F
long	sprCheckObject(ADV_MAIN *lpSpr);
//	�`��I�u�W�F�N�g���ւ�
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
//		�`��Ǘ����W���[���E�I��
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprFinish(void)
{
	long	nLoop;

	//	�`��Ǘ����W���[���E�폜
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		SprDestroy(&adv_main[nLoop]);
	}
}

//======================================================================
//		�`��Ǘ����W���[���E����
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
ADV_MAIN *spr_create(const char* lpszName,long nAlpha,int graph_h,int graph_w,int allnum,int xnum,int ynum)
{
	ADV_MAIN *lpSpr;
	
	// �t�@�C��������̏ꍇ�ɂ́Anullptr��Ԃ�
	if(strcmp(lpszName, "") == 0)
	{
		return	nullptr;
	}

	//	�`��Ǘ����W���[�����g�p���擾
	lpSpr = sprGetFreeObject();
	if(lpSpr == nullptr)
	{
		return nullptr;
	}
	
	//	DX���C�u�����E�f�ޓǍ�
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
//		�`��Ǘ����W���[���E�폜
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprDestroy(ADV_MAIN *lpSpr)
{
	long	nResult;
	int i;

	//	�`��Ǘ����W���[���m�F
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	//	DX���C�u�����E�f�ލ폜
	for(i = 0;i < 4;i++)
	{
		DeleteGraph(lpSpr->sprNo[i]);
	}
	//	�`��Ǘ����W���[����񏉊���
	InitObject(lpSpr);
}


//======================================================================
//		�`��Ǘ����W���[���E�`��
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprDraw(void)
{
	ADV_MAIN		*lpSpr;
	long			nLoop;

	//	�`��I�u�W�F�N�g���ւ�
	memset((void*)&adv_sub[0], 0x00, sizeof(ADV_MAIN) * ADV_MAX_MAIN);
	memcpy_s((void*)&adv_sub[0], sizeof(ADV_MAIN) * ADV_MAX_MAIN, (void*)&adv_main[0], sizeof(ADV_MAIN) * ADV_MAX_MAIN);
	qsort((void*)&adv_sub[0], ADV_MAX_MAIN, sizeof(ADV_MAIN), sprSort2dObject);
	
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		lpSpr = &adv_sub[nLoop];
		//	���g�p��Ԃ̏ꍇ
		if(lpSpr->bUsed != 1)
		{
			continue;
		}
		//	��\����Ԃ̏ꍇ
		if(lpSpr->g_show != GRA_ON)
		{
			continue;
		}
		//	DX���C�u�����E�`��
		fw::Draw(lpSpr->x, lpSpr->y, lpSpr->sprNo[(lpSpr->show_num / 14)], lpSpr->nAlpha);
	}
	
}

//======================================================================
//		�`��Ǘ����W���[���E�\���ʒu�ݒ�
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprSetPos(ADV_MAIN *lpSpr, long nX, long nY)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->x = nX;
	lpSpr->y = nY;

}

//======================================================================
//		�`��Ǘ����W���[���E�\���ʒu�擾
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprGetPos(ADV_MAIN *lpSpr, long *lpX, long *lpY)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
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
//		�`��Ǘ����W���[���E�\�����s���ݒ�
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprSetDepth(ADV_MAIN *lpSpr, long nZ)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->z = nZ;
}

//======================================================================
//		�`��Ǘ����W���[���E�ړ�
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprMove(ADV_MAIN *lpSpr, long nX, long nY)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->x += nX;
	lpSpr->y += nY;
}

//======================================================================
//		�`��Ǘ����W���[���E�\���ؑ�
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprShow(ADV_MAIN *lpSpr, long nShow)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
	nResult = sprCheckObject(lpSpr);
	if(nResult != 1)
	{
		return;
	}
	lpSpr->g_show = nShow;
}

//======================================================================
//		�`��Ǘ����W���[���E���g�p���擾
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
ADV_MAIN	*sprGetFreeObject(void)
{
	ADV_MAIN		*lpSpr;
	long			nLoop;

	lpSpr = NULL;
	//	���g�p��񌟍�
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
//		�`��Ǘ����W���[���E������
//		����N/��/��		�����
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
//		�`��Ǘ����W���[���E�m�F
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
long	sprCheckObject(ADV_MAIN *lpSpr)
{
	long	nResult;
	long	nLoop;

	nResult = 0;
	for(nLoop = 0; nLoop < ADV_MAX_MAIN; nLoop++)
	{
		//	���g�p��Ԃ̏ꍇ
		if(adv_main[nLoop].bUsed != 1)
		{
			continue;
		}
		//	������Ƃ͈قȂ�ꏊ
		if(&adv_main[nLoop] != lpSpr)
		{
			continue;
		}
		//	��v�����ꏊ�𔭌�
		nResult = 1;
		break;
	}

	return	nResult;
}

//======================================================================
//		�`��I�u�W�F�N�g���ւ�
//		����N/��/��		�����
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
//		�f�ރT�C�Y�擾
//		����N/��/��		�����
//		  2012/11/20		H.tanaka
//======================================================================
void	SprGetSize(ADV_MAIN *lpSpr, long *lpW, long *lpH)
{
	long	nResult;

	//	�`��Ǘ����W���[���m�F
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
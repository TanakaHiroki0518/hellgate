#include	<DxLib.h>
#include	"frameWork/hellsgate.h"


int		gate_main(ADV_MAIN	*lpsprGate,int dash_c,ADV_MAIN	*lpsprPl,CHARA_MAIN player,char Key[256],int map_c)
{
	if((lpsprGate->x + lpsprGate->w > lpsprPl->x) && (lpsprGate->x < lpsprPl->x + lpsprPl->w))
	{
		if(lpsprGate->y + lpsprGate->h > lpsprPl->y)
		{
			if(lpsprGate->show_num == 0)
			{
				lpsprPl->x = player.x;
				lpsprPl->y = player.y;
			}
		}
		if((lpsprPl->y <= (lpsprGate->y + lpsprGate->h + 10)) && (dash_c >= 1))
		{
			if(map_c == 2)
			{
				if(Key[KEY_INPUT_Z] != 0)
				{
					return 2;
				}
			}
			else if(map_c == 12)
			{
				if(dash_c >= 4)
				{
					if(Key[KEY_INPUT_Z] != 0)
					{
						return 5;
					}
				}
			}
		}
	}
	
	return dash_c;
}
#pragma warning(disable:4100)

#include	<iostream>
#include	<DxLib.h>
#include	"hellsgate.h"

int hp1;
int hp10;
int hp100;
DATEDATA date;



void	String_Draw(CHARA_MAIN	player,int string_c)
{
	//フォント
	SetFontSize(20);
	
	if((string_c >= 1)	&& (string_c <100))
	{
		if((string_c >= 1)	&& (string_c < 9))
		{
			if(string_c >= 1)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"***「･････により被告を死刑に処す。」");
			}
			if(string_c >= 2)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"こしか「俺はやってない！もう一度調べなおしてくれ！」");
			}
			if(string_c >= 3)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"***「早く被告人を連れて行け。」");
			}
			if(string_c >= 4)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"こしか「放せ！放してくれ！俺じゃないんだ！」");
			}
			if(string_c >= 5)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"･･････････････････");
			}
			if(string_c >= 6)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"･･････････");
			}
			if(string_c >= 7)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"････");
			}
		}

		if((string_c >= 9) && (string_c <17))
		{
			if(string_c >= 9)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"***「これより、死刑を執り行う。」");
			}
			if(string_c >= 10)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"こしか「俺の話を聞いてくれ！」");
			}
			if(string_c >= 11)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"被害者親族「兄貴を返せ！この人殺し！」");
			}
			if(string_c >= 12)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"こしか「だから俺は･････ｯ!!!」");
			}
			if(string_c >= 13)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"***「執行致します。」");
			}
			if(string_c >= 14)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"");
			}
			if(string_c >= 15)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"ﾄﾞｼｬｯ･･･");
			}
		}

		if((string_c >= 18) && (string_c <26))
		{
			if(string_c >= 18)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"こしか「どこだ、ここは･･･」");
			}
			if(string_c >= 19)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"こしか「これは･･･被害者の写真･･･？」");
			}
			if(string_c >= 20)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"こしか「ということは、被害者の家か？」");
			}
			if(string_c >= 21)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"***「ｷｷｷｯ逃亡者ﾊｯｹﾝ！ﾂｶﾏｴﾛ！」");
			}
			if(string_c >= 22)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"こしか「くっ、ドアが!?何とか逃げられないものか･･･」");
			}
			if(string_c >= 23)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"こしか「どこかにドアの鍵があるはずだ。」");
			}
			if(string_c >= 24)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"こしか「探し出して脱出してやる。」");
			}
		}
	}
	else if(string_c == 100)
	{
		GetDateTime(&date);
		DrawFormatString(20,(Widown_y + 20),WHITE,L"%d年%d月%d日%d時%d分%d秒",date.Year,date.Mon,date.Day,date.Hour,date.Min,date.Sec);
		DrawFormatString(20,(Widown_y + 45),WHITE,L"HP %d / %d",player.hp,player.max_hp);

	}
	else if(string_c == 101)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"ゲームを終了してよろしいですか？");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),WHITE,L"はい");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),WHITE,L"いいえ");
	}
	else if(string_c == 102)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"何番にセーブしますか？");
	}
	else if(string_c == 103)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"罪人よ我に何を望む");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),WHITE,L"回復");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),WHITE,L"アイテム");
	}
	else if(string_c == 104)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"死人の体力なぞ知るか");
	}
	else if(string_c == 105)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"調整中。何かキーを押してください。");
	}
	else if(string_c == 106)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"第一之門の鍵を見つけた");
	}
	else if(string_c == 107)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"第二之門の鍵を見つけた");
	}

	else if((string_c >= 200)	&& (string_c <218))
	{
		if((string_c >= 200)	&& (string_c < 209))
		{
			if(string_c >= 200)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"無事館から脱出できた。");
			}
			if(string_c >= 201)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"こしかは館で見つけた証拠を元に無罪を証明");
			}
			if(string_c >= 202)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"地獄の刑罰は逃れたのであった･･･");
			}
			if(string_c >= 203)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"");
			}
			if(string_c >= 204)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"fin");
			}
			if(string_c >= 205)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"");
			}
			if(string_c >= 206)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"");
			}
		}

		if((string_c >= 209) && (string_c <217))
		{
			if(string_c >= 209)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"地獄の門");
			}
			if(string_c >= 210)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"制作：IT-ｱｲﾃｨ-");
			}
			if(string_c >= 211)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"企画：石崎数馬");
			}
			if(string_c >= 212)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"プログラミング・グラフィック：田中弘樹");
			}
			if(string_c >= 213)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"サウンド：野坂治希");
			}
			if(string_c >= 214)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"Sprcial thanks：小鹿友平");
			}
			if(string_c >= 215)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"THANKYOU FOR PLAYING");
			}
		}
	}
}

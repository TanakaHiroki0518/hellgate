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
	//�t�H���g
	SetFontSize(20);
	
	if((string_c >= 1)	&& (string_c <100))
	{
		if((string_c >= 1)	&& (string_c < 9))
		{
			if(string_c >= 1)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"***�u������ɂ��퍐�����Y�ɏ����B�v");
			}
			if(string_c >= 2)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"�������u���͂���ĂȂ��I������x���ׂȂ����Ă���I�v");
			}
			if(string_c >= 3)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"***�u�����퍐�l��A��čs���B�v");
			}
			if(string_c >= 4)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"�������u�����I�����Ă���I������Ȃ��񂾁I�v");
			}
			if(string_c >= 5)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"������������������");
			}
			if(string_c >= 6)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"����������");
			}
			if(string_c >= 7)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"����");
			}
		}

		if((string_c >= 9) && (string_c <17))
		{
			if(string_c >= 9)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"***�u������A���Y������s���B�v");
			}
			if(string_c >= 10)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"�������u���̘b�𕷂��Ă���I�v");
			}
			if(string_c >= 11)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"��Q�Ґe���u�Z�M��Ԃ��I���̐l�E���I�v");
			}
			if(string_c >= 12)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"�������u�����牴�ͥ�����!!!�v");
			}
			if(string_c >= 13)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"***�u���s�v���܂��B�v");
			}
			if(string_c >= 14)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"");
			}
			if(string_c >= 15)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"�޼�����");
			}
		}

		if((string_c >= 18) && (string_c <26))
		{
			if(string_c >= 18)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"�������u�ǂ����A�����ͥ���v");
			}
			if(string_c >= 19)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"�������u����ͥ����Q�҂̎ʐ^����H�v");
			}
			if(string_c >= 20)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"�������u�Ƃ������Ƃ́A��Q�҂̉Ƃ��H�v");
			}
			if(string_c >= 21)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"***�u�������S��ʯ�݁I¶ϴہI�v");
			}
			if(string_c >= 22)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"�������u�����A�h�A��!?���Ƃ��������Ȃ����̂�����v");
			}
			if(string_c >= 23)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"�������u�ǂ����Ƀh�A�̌�������͂����B�v");
			}
			if(string_c >= 24)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"�������u�T���o���ĒE�o���Ă��B�v");
			}
		}
	}
	else if(string_c == 100)
	{
		GetDateTime(&date);
		DrawFormatString(20,(Widown_y + 20),WHITE,L"%d�N%d��%d��%d��%d��%d�b",date.Year,date.Mon,date.Day,date.Hour,date.Min,date.Sec);
		DrawFormatString(20,(Widown_y + 45),WHITE,L"HP %d / %d",player.hp,player.max_hp);

	}
	else if(string_c == 101)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"�Q�[�����I�����Ă�낵���ł����H");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),WHITE,L"�͂�");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),WHITE,L"������");
	}
	else if(string_c == 102)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"���ԂɃZ�[�u���܂����H");
	}
	else if(string_c == 103)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"�ߐl���ɉ���]��");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),WHITE,L"��");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),WHITE,L"�A�C�e��");
	}
	else if(string_c == 104)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"���l�̗̑͂Ȃ��m�邩");
	}
	else if(string_c == 105)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"�������B�����L�[�������Ă��������B");
	}
	else if(string_c == 106)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"���V��̌���������");
	}
	else if(string_c == 107)
	{
		DrawFormatString(20,(Widown_y + 20),WHITE,L"���V��̌���������");
	}

	else if((string_c >= 200)	&& (string_c <218))
	{
		if((string_c >= 200)	&& (string_c < 209))
		{
			if(string_c >= 200)
			{
				DrawFormatString(20,(Widown_y + 20),WHITE,L"�����ق���E�o�ł����B");
			}
			if(string_c >= 201)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"�������͊قŌ������؋������ɖ��߂��ؖ�");
			}
			if(string_c >= 202)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"�n���̌Y���͓��ꂽ�̂ł��������");
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
				DrawFormatString(20,(Widown_y + 20),WHITE,L"�n���̖�");
			}
			if(string_c >= 210)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),WHITE,L"����FIT-��è-");
			}
			if(string_c >= 211)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),WHITE,L"���F�΍萔�n");
			}
			if(string_c >= 212)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),WHITE,L"�v���O���~���O�E�O���t�B�b�N�F�c���O��");
			}
			if(string_c >= 213)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),WHITE,L"�T�E���h�F��⎡��");
			}
			if(string_c >= 214)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),WHITE,L"Sprcial thanks�F�����F��");
			}
			if(string_c >= 215)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),WHITE,L"THANKYOU FOR PLAYING");
			}
		}
	}
}

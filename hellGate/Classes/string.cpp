#include	<stdio.h>
#include	<stdlib.h>
#include	<DxLib.h>
#include	"frameWork/hellsgate.h"

int hp1;
int hp10;
int hp100;
DATEDATA date;



void	String_Draw(CHARA_MAIN	player,int string_c)
{
	//�t�H���g
	SetFontSize(20);
	//������̐F
	int Cr = GetColor(255,255,255);
	
	if((string_c >= 1)	&& (string_c <100))
	{
		if((string_c >= 1)	&& (string_c < 9))
		{
			if(string_c >= 1)
			{
				DrawFormatString(20,(Widown_y + 20),Cr,"***�u������ɂ��퍐�����Y�ɏ����B�v");
			}
			if(string_c >= 2)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),Cr,"�������u���͂���ĂȂ��I������x���ׂȂ����Ă���I�v");
			}
			if(string_c >= 3)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),Cr,"***�u�����퍐�l��A��čs���B�v");
			}
			if(string_c >= 4)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),Cr,"�������u�����I�����Ă���I������Ȃ��񂾁I�v");
			}
			if(string_c >= 5)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),Cr,"������������������");
			}
			if(string_c >= 6)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),Cr,"����������");
			}
			if(string_c >= 7)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),Cr,"����");
			}
		}

		if((string_c >= 9) && (string_c <17))
		{
			if(string_c >= 9)
			{
				DrawFormatString(20,(Widown_y + 20),Cr,"***�u������A���Y������s���B�v");
			}
			if(string_c >= 10)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),Cr,"�������u���̘b�𕷂��Ă���I�v");
			}
			if(string_c >= 11)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),Cr,"��Q�Ґe���u�Z�M��Ԃ��I���̐l�E���I�v");
			}
			if(string_c >= 12)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),Cr,"�������u�����牴�ͥ�����!!!�v");
			}
			if(string_c >= 13)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),Cr,"***�u���s�v���܂��B�v");
			}
			if(string_c >= 14)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),Cr,"");
			}
			if(string_c >= 15)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),Cr,"�޼�����");
			}
		}

		if((string_c >= 18) && (string_c <26))
		{
			if(string_c >= 18)
			{
				DrawFormatString(20,(Widown_y + 20),Cr,"�������u�ǂ����A�����ͥ���v");
			}
			if(string_c >= 19)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),Cr,"�������u����ͥ����Q�҂̎ʐ^����H�v");
			}
			if(string_c >= 20)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),Cr,"�������u�Ƃ������Ƃ́A��Q�҂̉Ƃ��H�v");
			}
			if(string_c >= 21)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),Cr,"***�u�������S��ʯ�݁I¶ϴہI�v");
			}
			if(string_c >= 22)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),Cr,"�������u�����A�h�A��!?���Ƃ��������Ȃ����̂�����v");
			}
			if(string_c >= 23)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),Cr,"�������u�ǂ����Ƀh�A�̌�������͂����B�v");
			}
			if(string_c >= 24)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),Cr,"�������u�T���o���ĒE�o���Ă��B�v");
			}
		}
	}
	else if(string_c == 100)
	{
		GetDateTime(&date);
		DrawFormatString(20,(Widown_y + 20),Cr,"%d�N%d��%d��%d��%d��%d�b",date.Year,date.Mon,date.Day,date.Hour,date.Min,date.Sec);
		DrawFormatString(20,(Widown_y + 45),Cr,"HP %d / %d",player.hp,player.max_hp);

	}
	else if(string_c == 101)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"�Q�[�����I�����Ă�낵���ł����H");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),Cr,"�͂�");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),Cr,"������");
	}
	else if(string_c == 102)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"���ԂɃZ�[�u���܂����H");
	}
	else if(string_c == 103)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"�ߐl���ɉ���]��");
		DrawFormatString((Wi_x + 60),(Wi_y + 20),Cr,"��");
		DrawFormatString((Wi_x + 60),(Wi_y + 60),Cr,"�A�C�e��");
	}
	else if(string_c == 104)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"���l�̗̑͂Ȃ��m�邩");
	}
	else if(string_c == 105)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"�������B�����L�[�������Ă��������B");
	}
	else if(string_c == 106)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"���V��̌���������");
	}
	else if(string_c == 107)
	{
		DrawFormatString(20,(Widown_y + 20),Cr,"���V��̌���������");
	}

	else if((string_c >= 200)	&& (string_c <218))
	{
		if((string_c >= 200)	&& (string_c < 209))
		{
			if(string_c >= 200)
			{
				DrawFormatString(20,(Widown_y + 20),Cr,"�����ق���E�o�ł����B");
			}
			if(string_c >= 201)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),Cr,"�������͊قŌ������؋������ɖ��߂��ؖ�");
			}
			if(string_c >= 202)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),Cr,"�n���̌Y���͓��ꂽ�̂ł��������");
			}
			if(string_c >= 203)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),Cr,"");
			}
			if(string_c >= 204)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),Cr,"fin");
			}
			if(string_c >= 205)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),Cr,"");
			}
			if(string_c >= 206)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),Cr,"");
			}
		}

		if((string_c >= 209) && (string_c <217))
		{
			if(string_c >= 209)
			{
				DrawFormatString(20,(Widown_y + 20),Cr,"�n���̖�");
			}
			if(string_c >= 210)
			{
				DrawFormatString(20,(Widown_y + 20 + 25),Cr,"����FIT-��è-");
			}
			if(string_c >= 211)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*2)),Cr,"���F�΍萔�n");
			}
			if(string_c >= 212)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*3)),Cr,"�v���O���~���O�E�O���t�B�b�N�F�c���O��");
			}
			if(string_c >= 213)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*4)),Cr,"�T�E���h�F��⎡��");
			}
			if(string_c >= 214)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*5)),Cr,"Sprcial thanks�F�����F��");
			}
			if(string_c >= 215)
			{
				DrawFormatString(20,(Widown_y + 20 + (25*6)),Cr,"THANKYOU FOR PLAYING");
			}
		}
	}
}

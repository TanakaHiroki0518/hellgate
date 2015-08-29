
#ifndef	__HELLGATE_H__
#define	__HELLGATE_H__

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <DxLib.h>
#include "Point.h"
#include <cstdarg>

//====================================================================================
//			�\���̂̐錾
//			����N/��/��		�����
//			  2012/10/29		H.tanaka
//====================================================================================

//	��ʃT�C�Y
#define	WINDOW_SIZE_W			(800)	//	��
#define	WINDOW_SIZE_H			(600)	//	�c
#define	WINDOW_COLOR			(16)	//	�F
#define	PL_GRAPH_SIZE			(32)	//	���@�O���t�B�b�N�T�C�Y


#define	ADV_MAX_MAIN	(2048)	//�摜�\������
#define	ADV_MAX_Z		(65535)	//�摜�ō��[�x

#define	GRA_ON			(1)		//�摜�\��
#define	GRA_OFF			(0)		//�摜��\��

#define	s_speed			(20)	//�w�i�X�N���[�����x

#define	map_h			(18)	//�}�b�v�}�X��
#define	map_w			(24)
#define maptip_size		(32)

#define map_waku_x		(16)	//�}�b�v�̊O�g
#define map_waku_y		(12)

#define map_speed		(16)
#define player_speed	(16)


#define map_num			(38)	//�}�b�v�`�b�v�̎��

#define ya_x			(565)	//���j���[��ʂ̃A�C�R���̏����ʒu
#define ya_y			(27)
#define ya2_x			(20)
#define ya2_y			(425)
#define Witop_x			(550)
#define Widown_y		(400)
#define Wi_x			(650)
#define Wi_y			(300)

//=========================================================
//		���@�X�e�[�^�X
//=========================================================
#define player_hp		(100)
#define player_atp		(1)
#define player_blp		(1)

//=========================================================
//		�G�@�X�e�[�^�X
//=========================================================
#define kobuta			(7)
#define enemy_h			(4)
#define enemy_w			(2)
#define enemy_hp		(3)
#define enemy_atp		(10)
#define enemy_blp		(0)
#define enemy_koshika	(35)

//=========================================================
//	�}�N��
//=========================================================
namespace fw
{
	/**
	 * @brief �����o�ϐ���`�p�}�N��
	 * @param[in] varType �����o�ϐ��̃f�[�^�^
	 * @param[in] varName �����o�ϐ��̖��O
	 * @param[in] funcName �����o�֐�getter��setter�̖��O
	 */
#define FW_SYNTHESIZE(varType, varName, funcName) \
private: \
	varType varName; \
public: \
	void set##funcName(varType var) { varName = var; }; \
	varType get##funcName() { return varName; };

	// getter�̂�
#define FW_SYNTHESIZE_READONLY(varType, varName, funcName) \
private: \
	varType varName; \
public: \
	varType get##funcName() { return varName; };

	// �������L
#define FW_SYNTHESIZE_WITHINIT(varType, varName, funcName, initVar) \
private: \
	varType varName = initVar; \
public: \
	void set##funcName(varType var) { varName = var; }; \
	varType get##funcName() { return varName; };

	// getter�̂݁A�������L
#define FW_SYNTHESIZE_WITHINIT_READONLY(varType, varName, funcName, initVar) \
private: \
	varType varName = initVar; \
public: \
	varType get##funcName() { return varName; };

	// �|�C���^�p
#define FW_SYNTHESIZE_POINTER(varType, varName, funcName) FW_SYNTHESIZE_WITHINIT(varType##*, varName, funcName, nullptr)

#define FW_SYNTHESIZE_POINTER_READONLY(varType, varName, funcName) FW_SYNTHESIZE_WITHINIT_READONLY(varType##*, varName, funcName, nullptr)

	// �֐��i�[�p
#define FW_CALLBACK_0(__selector__) std::bind(&__selector__)
#define FW_CALLBACK_1(__selector__) std::bind(&__selector__, std::placeholders::_1)
#define FW_CALLBACK_2(__selector__) std::bind(&__selector__, std::placeholders::_1, std::placeholders::_2)
#define FW_CALLBACK_3(__selector__) std::bind(&__selector__, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)

	// �F
#define COLOR_WHITE GetColor(255, 255, 255)

	//	DX���C�u�����E�`��
	inline int Draw(int x, int y, int gHandle, bool isAlpha)
	{
		int alpha = isAlpha ? TRUE : FALSE;
		return DrawGraph(x, y, gHandle, alpha);
	}

	inline std::string strPrintfWithFormat(const char* format, std::va_list arg){
		std::string ret;
		ret.resize(32); // ���̒l�͍����Ȃ��B���������傫���Ă��ǂ���������Ȃ��B
		auto n = static_cast<std::size_t>(vsnprintf(&ret[0], ret.size(), format, arg));

		if(n == static_cast<std::size_t>(-1)){
			n = _vscprintf(format, arg) + 1;
			ret.resize(n + 1);
			n = vsnprintf(&ret[0], ret.size(), format, arg);
		}
		ret.resize(n);
		return ret;
	}

	inline std::string getStrWithFormat(const char* fmt, ...){
		std::va_list varList;
		va_start(varList, fmt);
		std::string buf = strPrintfWithFormat(fmt, varList);
		va_end(varList);
		return buf;
	};

	inline int DrawLabel(const char* str, Point point, DWORD color, int fontSize = 20)
	{
		SetFontSize(fontSize);
		return DrawFormatString(point.x, point.y, color, str);
	}
}
#define USE_NS_FW using namespace fw;

typedef struct
{
	int png;
}
MAP_MAIN;


typedef	struct
{
	int	bUsed;		//	�g�p���
	int	nAlpha;		//	���ߐF�w��
	int	sprNo[4];		//	�f�ޔԍ�
	int	x;			//	x���W
	int	y;			//	y���W
	int	z;			//	�摜�̕\���[�x
	int	h;			//	�摜�̍���
	int	w;			//	�摜�̕�
	int	g_show;		//	�摜�g�p1=�g�p�A0=���g�p
	int allnum;		//	�摜�̕�����
	int x_num;		//	�摜�̉�������
	int y_num;		//	�摜�̏c������
	int show_num;	//	�\�����̉摜�̔ԍ�
	int dmg;
}
ADV_MAIN;

typedef struct
{
	int x;
	int y;
	int hp;
	int max_hp;
	int atp;
	int blp;
	int move_c;
	int dmg;
}
CHARA_MAIN;


//====================================================================================
//			�֐��̐錾
//			����N/��/��		�����
//			  2012/10/26		H.tanaka
//====================================================================================
//init.cpp
void gamemain(void);
ADV_MAIN* spr_create(const char* lpszName, long nAlpha, int graph_h, int graph_w, int allnum, int xnum, int ynum);
void SprDestroy(ADV_MAIN *lpSpr);
void SprFinish(void);
void SprDraw(void);
void SprSetPos(ADV_MAIN *lpSpr, long nX, long nY);
void SprGetPos(ADV_MAIN *lpSpr, long *lpX, long *lpY);
void SprSetDepth(ADV_MAIN *lpSpr, long nZ);
void SprMove(ADV_MAIN *lpSpr, long nX, long nY);
void SprShow(ADV_MAIN *lpSpr, long nShow);
void SprGetSize(ADV_MAIN *lpSpr, long *lpW, long *lpH);
void graph_shownum(ADV_MAIN	*lpspr);

//main.cpp


//map.cpp
void	MapMain(int map_c,int scroll,ADV_MAIN *lpspr);
void	MapGraphLoad(void);
void	MapInit(void);
void	atari_wall(ADV_MAIN	*lpspr,CHARA_MAIN	player,int map_c);
int atari_damage(ADV_MAIN *lpspr, int map_c);
int		damage_trap(ADV_MAIN	*lpspr,CHARA_MAIN player,int map_c);
int	damage_trap_enemy(ADV_MAIN	*lpspr,CHARA_MAIN enemy,int map_c);
int key_main(ADV_MAIN *lpspr, int map_c);


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

#endif	/*__HELLGATE_H__*/

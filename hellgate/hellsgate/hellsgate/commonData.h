/*
�ėp�f�[�^�i�[�p�w�b�_
 */

#ifndef __COMMON_DATA__H__
#define __COMMON_DATA__H__

//	��ʃT�C�Y
#define	WINDOW_SIZE_W			(800)	//	��
#define	WINDOW_SIZE_H			(600)	//	�c
#define	WINDOW_COLOR			(16)	//	�F
#define	PL_GRAPH_SIZE			(32)	//	�O���t�B�b�N�T�C�Y


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
//		�F
//=========================================================
#define WHITE GetColor(255,255,255) // ��

// �}�b�v�`�b�v�p�摜�i�[�\����
typedef struct
{
	int png;
} MAP_MAIN;

// �摜�X�e�[�^�X
typedef	struct
{
	int	bUsed;		//	�g�p���
	int	nAlpha;		//	���ߐF�w��
	int	sprNo[4];	//	�f�ޔԍ�
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
} ADV_MAIN;

// �L�����X�e�[�^�X
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
} CHARA_MAIN;

#endif /* __COMMON_DATA__H__ */

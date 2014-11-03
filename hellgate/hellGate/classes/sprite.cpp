/*
sprite�i�[�N���X
 */
#include "sprite.h"

// �e�p�X
#define GRAPHICS "resources\\graphic\\"

// �R���X�g���N�^
sprite::sprite()
: m_spr(NULL)
{
}

// �f�X�g���N�^
sprite::~sprite()
{
	delete[] m_spr;
}

// create
void sprite::createWithNode(const char* nodePath)
{
	// create
	m_spr = new spriteStatus();

	// �摜�̃��[�h
	m_spr->graphic = LoadGraph((const wchar_t*)this->convertGraPath(nodePath));
}

bool sprite::init()
{
	// spriteStatus�����ׂĂ̕ϐ��̏�����
	m_spr->graphic = 0;
	m_spr->isVisible = false;
	m_spr->pos_x = 0;
	m_spr->pos_y = 0;
	m_spr->zOrder = 0;
	m_spr->height = 0;
	m_spr->width = 0;
	m_spr->allnum = 0;
	m_spr->x_num = 0;
	m_spr->y_num = 0;
	m_spr->nAlpha = 0;

	return true;
}

const char* sprite::convertGraPath(const char* path)
{
	// �e�p�X
	std::string str = GRAPHICS;
	// �q�p�X�̒ǉ�
	str.append(path);

	return str.c_str();
}

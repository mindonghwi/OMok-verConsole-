#include "stdafx.h"

C_PLAYER::C_PLAYER():
	m_pStones(),
	m_strShape(""),
	m_nIndex(0)
{
}

C_PLAYER::~C_PLAYER()
{
}


void C_PLAYER::init(string strShape)
{
	m_strShape = strShape;
	m_pStones = new C_STONE[E_MAXSIZE * E_MAXSIZE / 2];
}

void C_PLAYER::release()
{
	delete[] m_pStones;
	m_pStones = nullptr;
}

void C_PLAYER::putStone(int nPosX, int nPosY)
{
	m_pStones[m_nIndex].setPos(nPosX, nPosY);
	m_nIndex++;
}
